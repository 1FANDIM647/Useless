Program Function_for_x ;
var x, k : integer ;

var s :string;
         
begin 
  
  k:=0;
 
    writeln('Введите x');
    readln(x);
   while x <> 0 do
   begin
     writeln('Введите x');
     readln(x);
     
     if x > 1 then
     begin
       k:= k +1;
     end;
   end;
  
   writeln(k);
   
end. 