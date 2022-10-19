from collections import deque

class stack:
    def __init__(self):
        self.input=deque()
        self.stackk=deque()
    def push(self,element):
        self.stackk.append(element)
    def pop(self):
        return self.stackk.pop()
    def top(self):
        return self.stackk[-1]
    def calc(self,exp):
        n=len(exp)
        z=exp.split()
        for x in z:
            self.input.append(x)
        n=len(self.input)
        for w in range(0,n):
            x=self.input.pop()
            if x not in "+-/*^":
                self.push(x)
            elif x =="+":
                v1=int(self.pop())
                v2=int(self.pop())
                self.push(v1+v2)
            elif x =="-":
                v1=int(self.pop())
                v2=int(self.pop())
                self.push(v1-v2)
            elif x =="*":
                v1=int(self.pop())
                v2=int(self.pop())
                self.push(v1*v2)
            elif x =="/":
                v1=int(self.pop())
                v2=int(self.pop())
                r=float(v1/v2)
                self.push(r)
    def print_res(self):
            print(self.pop())

        
obj=stack()
obj.calc("/ - * 2 5 * 1 2 - 11 9")
obj.print_res()            
