class Matrix:
    def __init__(self):
        self.r = 0
        self.c = 0
        self.l = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

    def matrixin(self):  # Function for taking output
        self.r = int(input("Enter the Number of rows :"))
        self.c = int(input("Enter the Number of column :"))
        self.l = []
        for i in range(self.r):
            row = []
            for j in range(self.c):
                row.append(int(input()))
            self.l.append(row)

    def matrixout(self):  # Function for printing output
        for i in range(self.r):
            for j in range(self.c):
                print(self.l[i][j], end=" ")
            print()

    def addition(self, temp):
        #   Function which perform the addition of two matrices
        if self.r == temp.r and self.c == temp.c:
            m3 = Matrix()
            m3.r = self.r
            m3.c = self.c
            for i in range(self.r):
                for j in range(self.c):
                    m3.l[i][j] = (self.l[i][j] + temp.l[i][j])
            return m3

        else:
            print("Error")

    def subtraction(self, temp):
        # Function which perform the substraction of two matrices
        if self.r == temp.r and self.c == temp.c:
            m3 = Matrix()
            m3.r = self.r
            m3.c = self.c
            for i in range(self.r):
                for j in range(self.c):
                    m3.l[i][j] = self.l[i][j] - temp.l[i][j]
            return m3

    def multmatrix(self, m):
        # Function which perform the multiplication of two matrices
        ans = Matrix()
        ans.r = self.r
        ans.c = m.c
        if self.c != m.r:
            print("Multiplication is not possible ")
            return 
        else:
            for i in range(ans.r):
                for j in range(ans.c):
                    for k in range(self.c):
                        ans.l[i][j] += self.l[i][k] * m.l[k][j]
            # ans.matrixout()
            return ans

    def transpose(self, a):
        # Function which find the transpose of given Matrix
        self.r = a.r
        self.c = a.c
        for i in range(self.r):
            for j in range(self.c):
                self.l[i][j] = a.l[j][i]


# Main
m1 = Matrix()
m1.matrixin()
m1.matrixout()

m2 = Matrix()
m2.matrixin()
m2.matrixout()
flag = True
while (flag):
    print("Hello..!")
    print("Enter 1:Addition")
    print("Enter 2:Subtraction")
    print("Enter 3:Multiplication")
    print("Enter 4:Transpose")
    print("Enter 5:Exit")
    ch = int(input("Enter your choice : "))
    if ch == 1:
      print("Matrix addition is ")
      m3 = Matrix()
      m3 = m1.addition(m2)
      m3.matrixout()
    elif ch == 2:
        print("Matrix subtraction is ")
        m4 = Matrix()
        m4 = m1.subtraction(m2)
        m4.matrixout()
    elif ch==3:
        print("Multiplication")
        m3 = m1.multmatrix(m2)
        m3.matrixout()
    elif ch==4:
          print("Transpose")
          m5 = Matrix()
          m5.transpose(m1)
          m5.matrixout()
    elif ch==5:
        print("Thank you")
        flag = False
    else:
        print("Enter the valid Input")








