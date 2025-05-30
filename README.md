# Conversão de Energia para Mods de Minecraft

Um algoritmo em C++ para conversão de diferentes unidades de energia utilizadas por mods populares do Minecraft, como FE (Forge Energy), RF (Redstone Flux), IF (Immersive Flux) e J (Joule).

## Descrição

Este projeto oferece uma ferramenta simples e eficiente para converter valores entre múltiplos sistemas de energia, considerando os prefixos de grandeza (K, M, G, T) frequentemente usados nesses mods. O sistema permite que jogadores, desenvolvedores e jogadores calculem rapidamente equivalências de energia entre mods, facilitando integrações e otimizações.

## Principais Funcionalidades

- **Conversão entre FE, RF, IF e J**  
  Suporte direto às unidades mais comuns dos mods.
- **Suporte a Prefixos**  
  Reconhecimento de prefixos como K (kilo), M (mega), G (giga) e T (tera) para facilitar conversões envolvendo grandes quantidades de energia.
- **Validação de entrada**  
  Checagem automática para garantir que as unidades inseridas são válidas.
- **Interface Simples via Terminal**  
  Interação rápida e intuitiva diretamente pelo console.
- **Código Extensível**  
  Fácil de adaptar para novas unidades ou mods, bastando editar os mapas de prefixos e unidades.

## Como Usar

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/DuqueIguro/Conversao-de-Energia.git
   ```
2. **Compile o código (exemplo para g++):**
   ```bash
   g++ -o conversor main.cpp
   ```
3. **Execute o programa:**
   ```bash
   ./conversor
   ```

## Exemplo de Uso

```
Conversor de Energia (FE, RF, J, IF)
-------------------------------------
Digite o valor: 1500
Digite a unidade de origem (ex: MFE, kIF, GJ): kRF
Digite a unidade de destino (ex: FE, MJ, kRF): MFE

Resultado: 1.5 MFE
```

## Lógica de Conversão

- O programa identifica o prefixo (K, M, G, T) e o converte para seu respectivo fator multiplicador.
- A unidade base (FE, RF, IF, J) é extraída e validada.
- O valor inserido é convertido para a unidade base comum e, em seguida, convertido para a unidade de destino informada, considerando todos os multiplicadores.
- Por padrão, as unidades FE, RF, IF e J são tratadas com equivalência 1:1. Basta adaptar a lógica caso algum mod utilize fatores diferentes.

## Tecnologias Utilizadas

- **C++** (padrão C++11+)
- STL: `unordered_map`, `iostream`, `iomanip`, `string`

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues, enviar sugestões ou criar pull requests para aprimorar o projeto.

1. Fork este repositório
2. Crie uma branch para sua feature/correção (`git checkout -b minha-feature`)
3. Faça commit das suas alterações (`git commit -m 'Minha nova feature'`)
4. Push para a branch (`git push origin minha-feature`)
5. Abra um pull request
