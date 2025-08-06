import csv
import re

grafo = {}

# Primeiros 1000 tweets (ou menos)
with open('twcs.csv', 'r', encoding='utf-8') as f:
    reader = csv.DictReader(f)
    count = 0
    for row in reader:
        if count >= 1000:
            break
        count += 1

        u = row['author_id']
        v = row['in_response_to_tweet_id']
        texto = row['text']

        # Criar aresta se houve resposta
        if v and u != v:
            grafo.setdefault(u, set()).add(v)
            grafo.setdefault(v, set()).add(u)

        # Criar aresta se mencionou alguém
        mencoes = re.findall(r'@(\w+)', texto)
        for m in mencoes:
            if m != u:
                grafo.setdefault(u, set()).add(m)
                grafo.setdefault(m, set()).add(u)

# Mapear usuários para índices
usuario_idx = {user: i for i, user in enumerate(grafo)}
n = len(usuario_idx)

# Criar matriz
matriz = [[0]*n for _ in range(n)]
for u, vizinhos in grafo.items():
    i = usuario_idx[u]
    for v in vizinhos:
        if v in usuario_idx:
            j = usuario_idx[v]
            matriz[i][j] = 1
            matriz[j][i] = 1

# Salvar
with open('matriz_adjacencia.txt', 'w') as f:
    f.write(f"{n}\n")
    for linha in matriz:
        f.write(' '.join(map(str, linha)) + '\n')
