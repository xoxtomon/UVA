from sys import stdin
from collections import deque
from itertools import chain, islice

def suffix_array(A):
    #algoritmo de Vladu and Negruşeri

    L = sorted((a, i) for i, a in enumerate(A))
    n = len(A)
    count = 1
    while count < n:

        P = [0] * n
        for (r, i), (s, j) in zip(L, islice(L, 1, None)):
            P[j] = P[i] + (r != s)

        L = sorted(chain((((P[i],  P[i+count]), i) for i in range(n - count)), 
                         (((P[i], -1), i) for i in range(n - count, n))))
        count *= 2
    return [i for _, i in L]

def inverse_suffix_array(sa):
    inverse_sa = [-1] * len(sa)
    for i, suffix in enumerate(sa):
        inverse_sa[suffix] = i
    return inverse_sa

def lcp_array(cadena, sa, inverse_sa):
    n = len(cadena)
    lcp= [-1] * n
    
    k = 0
    for i in range(n):
        if inverse_sa[i] == n-1:
            k=0
            continue;

        j = sa[inverse_sa[i]+1]
        while((i+k) < n and (j+k) < n and cadena[i+k]==cadena[j+k]):
            k+=1
        
        lcp[inverse_sa[i]] = k
        if k > 0:
            k-=1
    lcp.pop()
    lcp.insert(0,-1)
    return lcp

def lcs(cadena,sa,lcp):
    longMax = max(lcp)
    ans = {}
    for i in range(1, len(cadena)):
        if lcp[i] == longMax:
            x1, x2, offset = sa[i - 1], sa[i], lcp[i]
            assert cadena[x1:x1 + offset] == cadena[x2:x2 + offset]
            sbstr = cadena[x1:x1 + offset]
            if sbstr not in ans:
                ans[sbstr] = [x1]
            ans[sbstr].append(x2)
    return dict((k, sorted(v)) for k, v in ans.items())



def main():
    myRawInput = stdin.readlines()

    for i in range(1, len(myRawInput)):
        case = myRawInput[i].strip('\n')

        suffixArray = suffix_array(case)
        inverseSuffixArray = inverse_suffix_array(suffixArray)
        lcp = lcp_array(case, suffixArray,inverseSuffixArray)

        sol = lcs(case,suffixArray,lcp)
        fst = list(sol.items())[0]
        if(fst[0]):
            print(f'{fst[0]} {len(fst[1])}')
        else:
            print("No repetitions found!")


main()