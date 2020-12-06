from sys import stdin
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

def compute_lcs(sa,lcp,cad,dict):
    maxLen = 0
    ans = []

    for i in range(len(sa)-1):
        aux1 = cad[sa[i]:]
        aux2 = cad[sa[i+1]:]
        if dict[aux1] != dict[aux2] and lcp[i+1] >= maxLen:
            if lcp[i+1] > maxLen:
                maxLen = lcp[i+1]
                ans = []
            if aux2[:maxLen] not in ans:
                ans.append(aux2[:maxLen])
    if maxLen == 0:
        return []
    else:
        return ans

def main():
    myRawinput = stdin.readlines()
    indexes = [x for x in range(len(myRawinput)) if myRawinput[x] == '\n']
    indexes.append(len(myRawinput))
    
    for i in range(len(indexes)):
        myCase = []
        if i == 0:
            myCase = myRawinput[:indexes[i]]
        else:
            print()
            myCase = myRawinput[indexes[i-1]+1:indexes[i]]
        
        cadenaA = myCase[0].strip('\n')
        cadenaB = myCase[1].strip('\n')
        concat = cadenaA + '#' + cadenaB + '$'

        sa = suffix_array(concat)
        invSa = inverse_suffix_array(sa)
        lcp = lcp_array(concat,sa,invSa)

        for i in range(2):
            sa.pop(0)
            lcp.pop(0)
        
        src = {concat[sa[x]:]:2 for x in range(len(sa))}
        for i in src:
            if '#' in i:
                src[i]=1

        sol = compute_lcs(sa,lcp,concat,src)
        if len(sol)>0:
            for i in sol:
                print(i)
        else:
            print('No common sequence.')

main()