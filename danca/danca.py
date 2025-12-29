def permutar_coluna(matriz, coluna1, coluna2):
    temp = []
    for i in matriz:
        temp.append(i[coluna1 - 1])
        i[coluna1-1] = i[coluna2-1]
        i[coluna2-1] = temp[matriz.index(i)]

def permutar_linha(matriz, linha1, linha2):
    matriz[linha1 - 1], matriz[linha2 - 1] = matriz[linha2 - 1], matriz[linha1 - 1]

N, M, P = map(int, input().split())

matriz = [[j + 1 + i * M for j in range(M)] for i in range(N)]

ordens = []
for i in range(P):
    a, b, c = input().split()
    ordens.append([a, int(b), int(c)])

for i in ordens:
    if i[0] == 'C':
        permutar_coluna(matriz, i[1], i[2])
    elif i[0] == 'L':
        permutar_linha(matriz, i[1], i[2])

for i in matriz:
    print(*i)