# 📖 Manual do Usuário: Jogo da Forca

## 🎮 Bem-vindo ao Jogo da Forca!

O clássico jogo da forca foi adaptado para o terminal, permitindo que você desafie suas habilidades de adivinhar palavras de forma divertida e intuitiva.  
Siga este manual para aproveitar ao máximo a experiência.

---

## 🎯 Objetivo do Jogo

O objetivo é adivinhar a palavra secreta antes que o bonequinho na forca seja completado.  
Você tem **6 tentativas** para errar antes de perder o jogo.

---

## 🕹️ Como Jogar

### 1. Menu Inicial

Ao iniciar o jogo, você verá o menu principal com as seguintes opções:

- **1. Iniciar novo jogo:** Comece um jogo com uma palavra secreta escolhida aleatoriamente.
- **2. Inserir palavra secreta:** Permite que você insira a sua própria palavra para o desafio.
- **3. Escolher dificuldade:** Escolha entre os níveis **fácil**, **médio** ou **difícil**, que ajustam o tamanho da palavra secreta.
- **4. Exibir pontuação:** Consulte sua pontuação acumulada.
- **5. Sair do jogo:** Encerre o programa.

Digite o número correspondente à opção desejada e pressione **Enter**.

---

### 2. Durante o Jogo

- **Palavra secreta:** Representada por traços `_` para cada letra não adivinhada.
- **Digite uma letra:** Adivinhe uma letra e pressione **Enter**.

  - Se a letra estiver correta, ela aparecerá na posição correspondente.
  - Se a letra estiver errada, o número de tentativas será reduzido e um pedaço do bonequinho será desenhado.

**Detalhes exibidos durante o jogo:**
- **Progresso:** A palavra atualizada com as letras adivinhadas.
- **Letras erradas:** Letras já tentadas e incorretas.
- **Tentativas restantes:** Quantas chances você ainda possui.

---

### 3. Regras Importantes

- **Sem caracteres repetidos:** Se digitar uma letra já usada, o jogo pedirá outra.
- **Apenas letras são aceitas:** Números ou símbolos não são permitidos.
- **Você vence:** Quando adivinhar toda a palavra antes de errar 6 vezes.
- **Você perde:** Quando atingir 6 erros — a palavra secreta será revelada.

---

## 🧩 Opção de Inserir Palavra Secreta

Se escolher a opção **"Inserir palavra secreta"**, você poderá digitar uma palavra personalizada (até 50 caracteres).  
Essa palavra será utilizada na próxima rodada.

**Dica:** Não mostre a palavra para quem for jogar! 😉

---

## 💡 Dicas

- Comece pelas **vogais** — elas aparecem mais frequentemente.
- Observe as **letras já usadas** para evitar erros repetidos.
- Em dificuldades mais altas, **palavras mais longas** exigem mais atenção!

---

## ⚙️ Configurações do Terminal

Para exibir corretamente caracteres especiais ou desenhos:

```bash
chcp 65001
