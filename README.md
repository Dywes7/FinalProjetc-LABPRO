# Computação da Matriz SCM em Imagens
## Introdução
Este repositório contém a implementação em Linguagem C para calcular a Matriz de Coocorrência Estrutural (SCM) em imagens. A SCM é uma ferramenta essencial para descrever as características de uma imagem e, neste contexto, é aplicada em conjunto com experimentos de classificação utilizando a biblioteca Weka.
## Objetivos
O objetivo principal deste projeto é proporcionar uma implementação eficiente para a computação da SCM entre uma imagem e sua versão suavizada. O processo inclui a quantização da imagem, o cálculo da SCM e a vetorização dos valores resultantes, que são então gravados em um arquivo de características para análises posteriores.

## Pré-requisitos
Antes de executar o projeto, certifique-se de ter os seguintes pré-requisitos instalados:

Linguagem C (compilador GCC recomendado)
Weka (para análises de classificação)
Conjunto de imagens disponibilizado pelo professor no formato PGM.

## Como executar

1. Clone o repositório

```bash
git clone https://github.com/Dywes7/FinalProjetc-LABPRO
```

2. Compile o projeto usando o comando

```bash
make
```

3. Os arquivos binários dos programas são gerados no diretório `bin/` do repositório clonado.

4. Para gerar a matriz de coocorrência estrutural, utilize:

```bash
./bin/main.e  <Nível de quantização>
```
Substitua <Nível de quantização> pelo número desejado de níveis para quantização da imagem. Este processo gera a SCM, vetoriza os valores e grava as características em um arquivo de texto para análises subsequentes.
