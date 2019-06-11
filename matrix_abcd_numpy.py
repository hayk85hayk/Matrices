import numpy
import os
import random

def matrix_generator(file_list):
    for file_name in file_list:
        with open(file_name, 'w') as f:
            pass
    number_of_matrix = 10
    for i in range(number_of_matrix):
        m = random.randint(2, 5)
        n = m
        for file_name in file_list:
            with open(file_name, 'a+') as f:
                f.write(f'# {m} x {n}\n')
                for i in range(m):
                    f.writelines(str([random.randint(0, 99) for i in
                                range(n)]).replace('[','').replace(']','').replace(',','')+'\n')

#matrix_generator(['A.txt', 'B.txt', 'C.txt', 'D.txt'])

def sizeinfo(a, b, c, d):
    a = a.readline()
    b = b.readline()
    c = c.readline()
    d = d.readline()
    assert(a == b == c == d), "Sizes don't match"
    return a

def read_matrix(file_path):
    with open(file_path, 'r') as f:
        pass

def a_b_mult_c_d(list_a, list_b, list_c, list_d): # y = (a+b)*(c+d)
    a, b, c, d = numpy.array(list_a),numpy.array(list_b),numpy.array(list_c),numpy.array(list_d)
    t1 = numpy.add(a, b)
    t2 = numpy.add(c, d)
    y = numpy.dot(t1, t2)
    return y


if __name__ == '__main__':
    with open('Y_numpy.txt', 'w') as f:
        pass
    with open('A.txt') as afile:
        with open('B.txt') as bfile:
            with open('C.txt') as cfile:
                with open('D.txt') as dfile:
                    with open('Y_numpy.txt', 'a+') as result:
                        sizeinfo_a = sizeinfo(afile, bfile, cfile, dfile)
                        qty = 1
                        while sizeinfo_a and sizeinfo_a[0] == '#':
                            m = int(sizeinfo_a[1:].split()[0])
                            list_a = [None] * m
                            list_b = [None] * m
                            list_c = [None] * m
                            list_d = [None] * m
                            for i in range(m):
                                list_a[i] = list(map(int,afile.readline().replace(',','').split()))
                                list_b[i] = list(map(int, bfile.readline().replace(',', '').split()))
                                list_c[i] = list(map(int, cfile.readline().replace(',', '').split()))
                                list_d[i] = list(map(int, dfile.readline().replace(',', '').split()))
                            y = a_b_mult_c_d(list_a, list_b, list_c, list_d) ## y = (a+b)*(c+d)
                            result.write('#'+ str(qty)+'\n' + str(y).replace('[','').replace(']','') + '\n')
                            qty += 1
                            sizeinfo_a = sizeinfo(afile, bfile, cfile, dfile)


