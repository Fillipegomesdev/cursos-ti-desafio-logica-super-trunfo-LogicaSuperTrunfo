# 🃏 Projeto Super Trunfo — Comparações Avançadas com Atributos Múltiplos

## 📘 Descrição
Este projeto foi desenvolvido como parte da disciplina de **Programação em C**, e tem como objetivo aplicar estruturas, funções e comparações lógicas entre elementos com múltiplos atributos.  

O jogo segue a ideia de **Super Trunfo**, onde duas cartas são comparadas com base em critérios definidos pelo usuário.

---

## 🧠 Funcionalidades

- Cadastro de cartas com:
  - Nome da cidade
  - Código da carta (ex: A01, B02)
  - População
  - Área
  - PIB
  - Pontos turísticos
- Cálculo automático de:
  - **Densidade populacional**
  - **PIB per capita**
- Comparação entre duas cartas:
  - O usuário escolhe o atributo a ser comparado.
  - O sistema indica qual cidade vence.
- Exibição dos resultados formatados.

---

## 🏗️ Estrutura do Código

- `main()` → ponto de entrada do programa.
- Estrutura `struct Carta` → representa cada carta.
- Funções auxiliares:
  - `compararCartas()` → compara dois atributos.
  - `calcularDensidade()` e `calcularPibPerCapita()` → fazem cálculos automáticos.

---

## 🧩 Exemplo de Execução

```bash
============================
   SUPER TRUNFO - BRASIL
============================

Digite o código da carta 1: A01
Digite o nome da cidade 1: São Paulo
População: 12300000
Área (km²): 1521
PIB (bilhões): 700
Pontos turísticos: 45

Digite o código da carta 2: B02
Digite o nome da cidade 2: Curitiba
População: 1900000
Área (km²): 435
PIB (bilhões): 120
Pontos turísticos: 20

============================
Qual atributo deseja comparar?
1. População
2. Área
3. PIB
4. Pontos turísticos
5. Densidade populacional
6. PIB per capita
============================
> 6

🏆 Carta vencedora: **São Paulo**
Atributo comparado: PIB per capita
⚙️ Como Compilar e Executar
💻 Requisitos
Sistema operacional: Windows, Linux ou macOS

Compilador: GCC

Editor recomendado: VS Code
