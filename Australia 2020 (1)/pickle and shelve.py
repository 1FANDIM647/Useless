#pickle  send data tp  files with  format .dat
#shelve giveies access to files with format .dat
#fandimfromitaly@gmail.com

import pickle, shelve

print("Conservation of lists")

variety = ["onions" , "tomatos" , "cabage"]
shape = [ "full " , "by cubs" , "by tuble"]
brand = ["TOMATO" , "FOOD ITALY","Vagatables"]

f = open("pickles1.dat ","wb")


#write down data in   the created  file
pickle.dump(variety,f)
pickle.dump(shape,f)
pickle.dump(brand,f)
f.close()