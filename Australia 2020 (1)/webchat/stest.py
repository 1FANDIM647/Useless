def binary(number):
    result=''
    modulo = 0
    number_source = 0
  
    if number > 0:
        while number:
            modulo = number % 2
            result = result + str(modulo) 
            number_source = number // 2
        if number_source == 0:
            return result[::-1]      
        number = number_source  
    elif not number:
        return '0'
    else:
        return str(number)  