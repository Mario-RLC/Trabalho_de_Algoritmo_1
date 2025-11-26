Trabalho: Bee Monitor C. 
Integrantes: Davi Antony, Ian Moura, Jonas Sousa, Mário Rafael e Victor Hugo.
Disciplina: Algoritimos e Programação I.
Professora: Dra. Alcilene Dalília de Sousa.
Descrição: Sistema de cadastro e monitoramento de abelhas sem ferrão e
sensores ambientais associados.
Compilação: MinGW.
Execução: VSCode.
Bugs conhecidos:
01 - Caso o usuário ultrapasse a quantidade de caracteres do vetor nomePopular[40] ou do vetor nomeCientifico[50], o sistema armazenará apenas os valores digitados até o limite do vetor e o restante será cortado;
02 - O sistema não aceita "Ç" ou acentuações;
03 - O programa possui problemas caso o usuário envie valores float onde deveriam ser int;
04 - As informações cadastradas não permanecem após o programa ser encerrado.