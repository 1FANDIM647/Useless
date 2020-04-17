// DVS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#undef   UNICODE
#define  WIN32_LEAN_AND_MEAN
#define  DEFAULT_PORT   "8080"// Номер порта 
#define  DEFAULT_BUFLEN  1024 // Размер буфера  
#define  MAX_SIZ_ZAP     1024 // Максиальный размер запроса 
#define  MAX_SIZ_OTV     1024 // Максиальный размер Ответа  
#define  MAX_KOL_POT     1024 // Максимальнео количество потоков  
#include <windows.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h> 
#include <iostream> 
#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
using namespace std;
struct TPot {
    bool   SVO; // Свободен ли поток 
    SOCKET SOC; // сокет     
    char   ZAP[MAX_SIZ_ZAP]; // ЗАПРОС  
    char   OTV[MAX_SIZ_OTV]; // ОТВЕТ 
};

TPot POTS[MAX_KOL_POT];// Масив с потоками 


char BZAP[MAX_SIZ_ZAP * MAX_KOL_POT];// Буфер запросов 
char BOTV[MAX_SIZ_OTV * MAX_KOL_POT];// Буфер ОТветов 


DWORD  WINAPI  ObrZap(LPVOID lpParam)
{  //-----------------------------------------------------------------------


 // Чтение данных в большой масив из сокета  
 // Ожидание ответа 
 // Вывод ответа в сокет 
    int NOMPOT = (int)lpParam;
    char* Zap = new char[DEFAULT_BUFLEN];// Буфер запроса 
    int ZapSi;// Количество поступивших данных из интернета 
    int OtpSi;// Колчиество отправленых байт клиенту 
    SOCKET ClientSocket = POTS[NOMPOT].SOC;





    //ZapSi  = recv(
    // ClientSocket, 
    // Zap, 
    // DEFAULT_BUFLEN,// Максимальное количество данных  
    //  0);// Читаем данные 
    ZapSi = recv(
        ClientSocket,
        &BZAP[NOMPOT * MAX_SIZ_ZAP],
        DEFAULT_BUFLEN,// Максимальное количество данных  
        0);// Читаем данные 

            // Передти в спящий режим потоку 0.1 секунды 


    char Otv[] =
        "HTTP/1.1 200 OK\r\n"
        "Content-Language: ru\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 6\r\nConnection: close\r\n\r\n"
        "Privet"
        "\r\n\r\n\0";


    std::cout << NOMPOT << std::endl;
    OtpSi = send(ClientSocket, Otv, sizeof(Otv), 0);   // Отдаем данные 
    closesocket(ClientSocket);
    POTS[NOMPOT].SVO = true;// Указываем что поток свободен 
    return 0;
}  //-----------------------------------------------------------------------


DWORD  WINAPI  Server(LPVOID lpParam) {

    SOCKET ListenSocket = (SOCKET)lpParam;
    SOCKET ClientSocket = INVALID_SOCKET;

    do {
        // Accept a client socket
        ClientSocket = accept(ListenSocket, NULL, NULL);

        if (ClientSocket == INVALID_SOCKET)  closesocket(ClientSocket);
        else {

            int f = 1;// ищим свободный поток 
            while ((f < MAX_KOL_POT) & (POTS[f].SVO != true)) f++;

            if (f < MAX_KOL_POT) {

                POTS[f].SVO = false;// Указываем что поток занят 
                POTS[f].SOC = ClientSocket;// Передаем сокет в поток   
                CreateThread( // Если Есть места для создания новых потоков
                    NULL,         // атрибуты безопасности по умолчанию
                    0,            // размер стека используется по умолчанию
                    ObrZap,       // функция потока
                    (LPVOID)f,       // аргумент функции потока Номер в масиве потока 
                    0,            // флажки создания используются по умолчанию
                    NULL);        // возвращает идентификатор потока

            }
            else {      // Если нет места для создания новых потоков 
     // --------------------------------------------------
            }


        }

    } while (true);




}



DWORD  WINAPI  ObrZap(LPVOID lpParam)
{  //-----------------------------------------------------------------------


 // Чтение данных в большой масив из сокета  
 // Ожидание ответа 
 // Вывод ответа в сокет 

    char* Zap = new char[DEFAULT_BUFLEN];// Буфер запроса 
    int ZapSi;// Количество поступивших данных из интернета 
    int OtpSi;// Колчиество отправленых байт клиенту 
    SOCKET ClientSocket = (SOCKET)lpParam;
    ZapSi = recv(
        ClientSocket,
        Zap,
        DEFAULT_BUFLEN,// Максимальное количество данных  
        0);// Читаем данные 

    char Otv[] =
        "HTTP/1.1 200 OK\r\n"
        "Content-Language: ru\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 6\r\nConnection: close\r\n\r\n"
        "Privet"
        "\r\n\r\n\0";

    OtpSi = send(ClientSocket, Otv, sizeof(Otv), 0);   // Отдаем данные 
    closesocket(ClientSocket);
    return 0;
}  //---------------------------------------


int main()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult =
        getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket =
        socket(
            result->ai_family,
            result->ai_socktype,
            result->ai_protocol
        );
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }


    // Setup the TCP listening socket
    iResult = bind(
        ListenSocket,
        result->ai_addr,
        (int)result->ai_addrlen);

    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }


    do {
        // Accept a client socket
        ClientSocket = accept(ListenSocket, NULL, NULL);



        if (ClientSocket == INVALID_SOCKET)  closesocket(ClientSocket);
        else {

            CreateThread(
                NULL,         // атрибуты безопасности по умолчанию
                0,            // размер стека используется по умолчанию
                ObrZap,       // функция потока
                (LPVOID)ClientSocket,         // аргумент функции потока
                0,            // флажки создания используются по умолчанию
                NULL);        // возвращает идентификатор потока



        }

    } while (true);


    const char** zzz = &source_str;
    size_t source_size = strlen(source_str);
    size_t* szz = &source_size;
    /* получить доступные платформы */
    cl_int ret;
    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    if (ret == 0)     std::cout << "clGetPlatformIDs             OK." << std::endl;
    else std::cout << "clGetPlatformIDs          Error " << ret << "." << std::endl;
    /* получить доступные устройства */
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
    if (ret == 0)     std::cout << "clGetDeviceIDs               OK." << std::endl;
    else std::cout << "clGetDeviceIDs            Error " << ret << "." << std::endl;
    /* создать контекст */
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
    if (ret == 0)     std::cout << "clCreateContext              OK." << std::endl;
    else std::cout << "clCreateContext           Error " << ret << "." << std::endl;
    /* создаем команду */
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
    if (ret == 0)     std::cout << "clCreateCommandQueue         OK." << std::endl;
    else std::cout << "clCreateCommandQueue      Error " << ret << "." << std::endl;
    /* создать бинарник из кода программы */
    program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);
    if (ret == 0)     std::cout << "clCreateProgramWithSource    OK." << std::endl;
    else std::cout << "clCreateProgramWithSource Error " << ret << "." << std::endl;
    /* скомпилировать программу */
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    if (ret == 0)     std::cout << "clBuildProgram               OK." << std::endl;
    else std::cout << "clBuildProgram            Error " << ret << "." << std::endl;
    /* создать кернел */
    cl_kernel kernel = clCreateKernel(program, "test", &ret);
    if (ret == 0)     std::cout << "clCreateKernel               OK." << std::endl;
    else std::cout << "clCreateKernel            Error " << ret << "." << std::endl;
    cl_mem MZAP = NULL;// структура описывающая Буфер где храняться запросы 
    cl_mem MOTV = NULL;// структура описывающая Буфер где храняться ответы 

    //int memLenth = sizeof(BZAP);
    //cl_char* mem = (cl_char *)malloc(sizeof(cl_char) * memLenth);

    /* создать буфер  для запросов */
    //memobj = clCreateBuffer(context, CL_MEM_READ_WRITE, memLenth * sizeof(cl_char), NULL, &ret);
    MZAP = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(BZAP) * sizeof(cl_char), NULL, &ret);
    if (ret == 0)     std::cout << "clCreateBuffer               OK." << std::endl;
    else std::cout << "clCreateBuffer            Error " << ret << "." << std::endl;

    /* создать буфер для ответов */
    MOTV = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(BOTV) * sizeof(cl_char), NULL, &ret);
    if (ret == 0)     std::cout << "clCreateBuffer               OK." << std::endl;
    else std::cout << "clCreateBuffer            Error " << ret << "." << std::endl;

    //-----------

    /* устанавливаем параметр запросы */
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&MZAP);
    if (ret == 0)     std::cout << "clSetKernelArg               OK." << std::endl;
    else std::cout << "clSetKernelArg            Error " << ret << "." << std::endl;

    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&MOTV);
    if (ret == 0)     std::cout << "clSetKernelArg               OK." << std::endl;
    else std::cout << "clSetKernelArg            Error " << ret << "." << std::endl;


    /* записать данные в буфер записываем поступившие запросы  */
    ret = clEnqueueWriteBuffer(command_queue, MZAP, CL_TRUE, 0, sizeof(BZAP) * sizeof(cl_char), BZAP, 0, NULL, NULL);
    if (ret == 0)     std::cout << "clEnqueueWriteBuffer         OK." << std::endl;
    else std::cout << "clEnqueueWriteBuffer      Error " << ret << "." << std::endl;

    size_t global_work_size[1] = { 1 };// Количество потоков наверно )))
    /* выполнить кернел */
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);
    if (ret == 0)     std::cout << "clEnqueueNDRangeKernel       OK." << std::endl;
    else std::cout << "clEnqueueNDRangeKernel    Error " << ret << "." << std::endl;
    /* считать данные из буфера */
    ret = clEnqueueReadBuffer(command_queue, MOTV, CL_TRUE, 0, sizeof(BOTV) * sizeof(cl_char), BOTV, 0, NULL, NULL);
    if (ret == 0)     std::cout << "clEnqueueReadBuffer          OK." << std::endl;
    else std::cout << "clEnqueueReadBuffer       Error " << ret << "." << std::endl;

    int f = 0;
    while (BOTV[f] != 0) { std::cout << BOTV[f]; f++; }

    closesocket(ClientSocket);
    WSACleanup();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
