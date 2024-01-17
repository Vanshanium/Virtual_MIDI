class imaginary_number:

    X = 0

    def __init__(self,input_a,input_b):
        self.real = input_a
        self.imaginary = input_b
    
    def print_num(self):
        print(f"{self.real}+{self.imaginary}i")

class imamginary_operators:


    def __init__(self,input_a,input_b):

        self.num_a = input_a
        self.num_b = input_b


    def imag_add(self,num_a,num_b):

        real = num_a.real + num_b.real

        imagine = num_a.imaginary + num_b.imaginary

        return imaginary_number(real,imagine)
    
    def scaler_multipy(self,num_a,num_b):

        real = num_a.real * num_b.real

        imagine = num_a.imaginary * num_b.imaginary

        return imaginary_number(real,imagine)




num_1 = imaginary_number(8,19)

num_2 = imaginary_number(19,89)
