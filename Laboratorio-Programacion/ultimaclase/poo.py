class Persona:

    def __init__(self):
        self.nombre = ""
        self.edad = 0
        
    def setEdad(self,edad):
        self.edad = edad

    def setNombre(self,nombre):
        self.nombre = nombre

    def printPersona(self):
        print("Nombre: "+ self.nombre +" Edad: "+str(self.edad))

    def esMayorQue(self,persona):
        if self.edad > persona.edad:
            return True
        return False


#con el tab se idican que las clases estan dentro

#la definicion de las clases debe estar arriba, se interpreta linea por linea
#inicio del programa
#print() para poder realizar un print de lo que fuese 
#para copiar una lista l3 = l2[:] sino, al igualarlo apuntan a la misma posicion de memoria
p1 = Persona()
p1.setNombre("Pedro")
p1.setEdad(99)
p1.printPersona()
p2 = Persona()
p2.setNombre("claudia")
p2.setEdad(50)

print(p1.esMayorQue(p2))

lista = [p1,p2,p1,p2]

#for i=0, i<len(lista), i+=1:
for pAux in lista:
#    pAux = lista
    pAux.printPersona()

#lista2 = [0,1,2,3,4,5]
# el ultimo te muestra de en cuanto a cuanto va 


for i in range(0,10,2):
    print(i)

#de forma rara
for i in range(0, len(lista)):
    print(i)
    pAux = lista[i]
    pAux.printPersona()

