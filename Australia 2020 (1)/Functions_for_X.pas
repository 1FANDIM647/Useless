// Программа которая считает
// разные значения при  переменной x
Program Function_for_x;

var x ,k  : integer;
var x1 ,k1: real;
var s :string; 
 
begin
  

writeln('Введите тип перемменной:');
readln(s);
if s = 'int' then
// если  тип int  
begin
  writeln('Введите  x :');
  readln(x);
  if x > 1 then
      begin
        k:= k + 1;
      end
  else
      begin
     
       if x = 0 then
           begin
               writeln('Если постоянно возращаться к вводу x , то это будет бесконечный цикл');  
           end;
      end;
   writeln(k);
  
end;

if s = 'double' then
begin
writeln('Введите  x :');
  readln(x1);
  if x1 > 1 then
      begin
        k1:= k1 + 1;
      end
  else
      begin
     
       if x1 = 0 then
           begin
               writeln('Если постоянно возращаться к вводу x , то это будет бесконечный цикл');  
           end;
      end;
   writeln(k1);
end;
 
end.
