# 🧠 Projeto: Problema do Clique

Este projeto tem como objetivo detectar **cliques** em grafos representando redes sociais, utilizando um **algoritmo guloso** implementado em linguagem C. O foco principal é a identificação de grupos densamente conectados entre usuários do Twitter, além da comparação experimental com o benchmark clássico **Zachary's Karate Club**.

---

## 📌 Descrição

O problema do clique consiste em encontrar subconjuntos de vértices em um grafo onde todos os vértices estejam **diretamente conectados entre si** (grafo completo). Neste projeto, aplicamos uma **abordagem gulosa** para encontrar cliques locais, utilizando uma **matriz de adjacência** como entrada.

Além disso, analisamos o artigo científico ["Finding All Maximal Connected s-Cliques in Social Networks" (EDBT 2018)](https://openproceedings.org/2018/conf/edbt/paper-28.pdf), relacionando sua abordagem com o algoritmo implementado aqui.

Os códigos foram implementados no Arch Linux e Ubuntu, testados em ambos e também no Windows 11.

---

## 🧰 Tecnologias Utilizadas

- Linguagem C (para detecção de cliques)
- Python (para pré-processamento dos dados e geração da matriz de adjacência)
- Dataset do Kaggle: [Customer Support on Twitter](https://www.kaggle.com/datasets/thoughtvector/customersupport-on-twitter)
- Benchmark: Grafo **Zachary's Karate Club**

---

## ⚙️ Como Usar o Programa

### 1. Compile o código em C:

```bash
gcc click.c -o click
```

### 2. Execute com uma matriz de adjacência como argumento:
```bash
./click <nome do arquivo .txt>
```
### 🔎 Pré-processamento (Python)
Antes de executar o código C, gere a matriz de adjacência a partir do arquivo twcs.csv.
Observação: Por limitações de desempenho, o script Python está configurado para ler apenas os 1000 primeiros tweets do arquivo, evitando travamentos em máquinas comuns.

---

## 📊 Avaliação Experimental
O algoritmo foi testado com:
- Dataset real do Twitter (1000 tweets)
- Grafo clássico Karate Club (34 vértices)
Métricas como tempo de execução, número de cliques e tamanho máximo foram registradas e estão no relatório final.

### 📑 Relatório
O relatório completo com análise do artigo, justificativas do algoritmo e resultados está disponível no arquivo Relatorio.docx.

---
## 👨‍💻 Autores
- Marcus Vinícius
- Filipe Gabriel
