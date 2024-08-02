lista=[5,8,15,23,8,27,2,3,13,30] #ovo su vrednosti koje su vec date
lista2=[]
x=len(lista)
for i in lista:
    while x>0:
        if lista[i]%3==0:
            lista2.append(i)
        else:
            lista2.append(0)
    x=x-1
print(lista2)
print('Hey')

