"""
Estudiante: Julian Andres Galvis Tocora
Profesor: Carlos Ramirez 
Codigo: 8974868
Tarea 1
"""
from sys import stdin

# Punto 1

def verificarDiagonales(mat):
	ans = True
	i=0
	last = -1
	first = 0
	while i < len(mat) and ans:
		if mat[i][first] == mat[i][last]:
			i+=1
			first +=1
			last -= 1
		else:
			ans = False

	return ans

# Punto 2

def esCapicua(m):
	ans = True
	i=0
	last=-1
	while i< (len(m)//2) and ans:
		if m[i] == m[last]:
			i+=1
			last-=1
		else:
			ans = False

	return ans

# Punto 3

# A
def diferenciaListas (list1,list2):
	ans=[]
	i=0
	while i < len(list1):
		if list1[i] in list2:
			list2.remove(list1[i])
		else:
			ans.append(list1[i])

		i+=1

	return ans

# B

def leerImprimir():
	num = int(stdin.readline())
	i=0
	while i < num:
		lista= stdin.readline()
		lista= lista.split(" ")
		lista2= stdin.readline()
		lista2= lista2.split(" ")
		lista.pop(0)
		lista2.pop(0)
		for n in range(len(lista)):
			lista[n]=int(lista[n])
		for m in range(len(lista2)):
			lista2[m]=int(lista2[m])
		diferencia= diferenciaListas(lista,lista2)
		y = 0
		while y < len(diferencia) - 1:
			print("%d, "%(diferencia[y]),end='')
			y+=1
		print("%d"%(diferencia[y]))

		i+=1

# Punto 4
def siEsPrimo(a):
        ans = True
        if a <= 1:
                ans = False
        i = 2
        while i < a and ans:
                if a % i ==0:
                        ans = False
                i+=1
        return ans

def sumaDigitos(n):    
        sum = 0
        while n != 0:
                sum += n % 10
                n //= 10
        return sum
        

        
def mostrarPrimos(n):
        lista=[]
        for i in range(2,n+1):
                if siEsPrimo(i):
                        lista.append(i)
        for a in range(len(lista)-1):
                print("--> %d,"%(lista[a]))
        print("--> %d"%(lista[a+1]))
        print("")
        print("Números entre 1 y 100 con suma de dígitos con valor primo:")
        lista2=[]
        for s in range (len(lista)):
                h=sumaDigitos(lista[s])
                if siEsPrimo(h):                       
                        lista2.append(lista[s])
        
        for n in range (len(lista2)-1):
                print("%d, "%(lista2[n]),end='')
        print("%d"%(lista2[n+1]))
        
                        

# Punto 5

def sumarValoresMatriz(disp,listp):
        ans = 0
        i = 0
        while i < len(listp):
                if listp[i][0] in disp:
                        n = 0
                        dispL=disp[listp[i][0]]
                        while n < len(dispL) :
                                if listp[i][1] == dispL[n][0]:
                                        ans+= dispL[n][1]
                                n+=1
                i+=1
        
        return ans























