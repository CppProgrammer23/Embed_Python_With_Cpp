

class Student:
    def __init__(self,name,age):
        self.age=age
        self.name=name
        self.ls= []
        self.ls.append([age,name])
    def addStudent(self,age,name):
        self.ls.append([age,name])
    def show(self):
        print('the student\'s list: ')
        for i in self.ls:
            print(i[1],'his age is: ',i[0])
        print('------------------')


def mul(a,b):
    return a*b