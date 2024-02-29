import cmath
#for P&M 8.27
def zEff(freq:float):
    C = 5*(10**-10) #in Farads
    R = 1000 #in Ohms
    L = 2*(10**-3) # in Henries
    omega = freq * 2 * cmath.pi

    rtn:complex = 0
    numerator = (1)
    denominator = (
        1/R+
        1/(omega * L * 1j)
        -omega*C/1j
    )
    return numerator/denominator
    #computes the effective impedence when given the frequency


'''
if __name__ == "__main__":
    print("f = 10kHz, zeff=", zEff(10000))
    print("f = 10MHz, zeff=", zEff(10**7))
'''