// FreeCell no terminal - C++17 (Procedural, sem struct-methods, sem templates e legível)
// Compilar: g++ -std=c++17 -O2 -Wall -Wextra -o freecell freecell.cpp
// Executar: ./freecell [semente]

#include <iostream>
#include <random>

using namespace std;

// ---------------------------------------------------------------- Estruturas de Dados Puras

struct Carta {
    int valor = 0; // 1 (Ás) .. 13 (Rei)
    int naipe = 0; // 0 = paus, 1 = ouros, 2 = copas, 3 = espadas
};

struct CelulaLivre {
    Carta carta;
    bool esta_ocupada = false;
};

struct VetorCartas {
    Carta* elementos = nullptr;
    size_t capacidade = 0;
    size_t tamanho = 0;
};

struct Posicao {
    enum TipoPosicao { Invalida, Coluna, Celula, Fundacao } tipo = Invalida;
    int indice = 0;
};

struct EstadoJogo {
    VetorCartas colunas[8];
    CelulaLivre celulas_livres[4];
    int fundacoes[4] = {0, 0, 0, 0}; // Maior valor já salvo em cada naipe
};

struct VetorEstados {
    EstadoJogo* elementos = nullptr;
    size_t capacidade = 0;
    size_t tamanho = 0;
};

// ---------------------------------------------------------------- Gerenciamento do VetorCartas

void vetorCartasRealocar(VetorCartas& vetor, size_t nova_capacidade) {
    Carta* novos_elementos = new Carta[nova_capacidade];
    for (size_t i = 0; i < vetor.tamanho; ++i) {
        novos_elementos[i] = vetor.elementos[i];
    }
    delete[] vetor.elementos;
    vetor.elementos = novos_elementos;
    vetor.capacidade = nova_capacidade;
}

void vetorCartasAdicionar(VetorCartas& vetor, const Carta& nova_carta) {
    if (vetor.tamanho == vetor.capacidade) {
        vetorCartasRealocar(vetor, vetor.capacidade == 0 ? 8 : vetor.capacidade * 2);
    }
    vetor.elementos[vetor.tamanho++] = nova_carta;
}

void vetorCartasRemoverUltimo(VetorCartas& vetor) {
    if (vetor.tamanho > 0) {
        --vetor.tamanho;
    }
}

void vetorCartasLimpar(VetorCartas& vetor) {
    vetor.tamanho = 0;
}

void vetorCartasRedimensionar(VetorCartas& vetor, size_t novo_tamanho) {
    if (novo_tamanho > vetor.capacidade) {
        vetorCartasRealocar(vetor, novo_tamanho);
    }
    vetor.tamanho = novo_tamanho;
}

bool vetorCartasEstaVazio(const VetorCartas& vetor) {
    return vetor.tamanho == 0;
}

size_t vetorCartasObterTamanho(const VetorCartas& vetor) {
    return vetor.tamanho;
}

Carta& vetorCartasObterEm(VetorCartas& vetor, size_t indice) {
    return vetor.elementos[indice];
}

const Carta& vetorCartasObterEm(const VetorCartas& vetor, size_t indice) {
    return vetor.elementos[indice];
}

Carta& vetorCartasObterUltimo(VetorCartas& vetor) {
    return vetor.elementos[vetor.tamanho - 1];
}

const Carta& vetorCartasObterUltimo(const VetorCartas& vetor) {
    return vetor.elementos[vetor.tamanho - 1];
}

void vetorCartasCopiar(VetorCartas& destino, const VetorCartas& origem) {
    vetorCartasLimpar(destino);
    for (size_t idx = 0; idx < vetorCartasObterTamanho(origem); ++idx) {
        vetorCartasAdicionar(destino, vetorCartasObterEm(origem, idx));
    }
}

void vetorCartasLiberarMemoria(VetorCartas& vetor) {
    delete[] vetor.elementos;
    vetor.elementos = nullptr;
    vetor.capacidade = 0;
    vetor.tamanho = 0;
}

// ---------------------------------------------------------------- Gerenciamento do Estado e VetorEstados

void copiarEstadoJogo(EstadoJogo& destino, const EstadoJogo& origem) {
    for (int col_idx = 0; col_idx < 8; ++col_idx) {
        vetorCartasCopiar(destino.colunas[col_idx], origem.colunas[col_idx]);
    }
    for (int cel_idx = 0; cel_idx < 4; ++cel_idx) {
        destino.celulas_livres[cel_idx] = origem.celulas_livres[cel_idx];
    }
    for (int naipe_idx = 0; naipe_idx < 4; ++naipe_idx) {
        destino.fundacoes[naipe_idx] = origem.fundacoes[naipe_idx];
    }
}

void liberarMemoriaEstado(EstadoJogo& estado) {
    for (int col_idx = 0; col_idx < 8; ++col_idx) {
        vetorCartasLiberarMemoria(estado.colunas[col_idx]);
    }
}

void vetorEstadosRealocar(VetorEstados& vetor, size_t nova_capacidade) {
    EstadoJogo* novos_elementos = new EstadoJogo[nova_capacidade];
    for (size_t idx = 0; idx < vetor.tamanho; ++idx) {
        copiarEstadoJogo(novos_elementos[idx], vetor.elementos[idx]);
        liberarMemoriaEstado(vetor.elementos[idx]);
    }
    delete[] vetor.elementos;
    vetor.elementos = novos_elementos;
    vetor.capacidade = nova_capacidade;
}

void vetorEstadosAdicionar(VetorEstados& vetor, const EstadoJogo& novo_estado) {
    if (vetor.tamanho == vetor.capacidade) {
        vetorEstadosRealocar(vetor, vetor.capacidade == 0 ? 8 : vetor.capacidade * 2);
    }
    copiarEstadoJogo(vetor.elementos[vetor.tamanho++], novo_estado);
}

void vetorEstadosRemoverUltimo(VetorEstados& vetor) {
    if (vetor.tamanho > 0) {
        liberarMemoriaEstado(vetor.elementos[vetor.tamanho - 1]);
        --vetor.tamanho;
    }
}

void vetorEstadosLimpar(VetorEstados& vetor) {
    for (size_t idx = 0; idx < vetor.tamanho; ++idx) {
        liberarMemoriaEstado(vetor.elementos[idx]);
    }
    vetor.tamanho = 0;
}

bool vetorEstadosEstaVazio(const VetorEstados& vetor) {
    return vetor.tamanho == 0;
}

size_t vetorEstadosObterTamanho(const VetorEstados& vetor) {
    return vetor.tamanho;
}

EstadoJogo& vetorEstadosObterUltimo(VetorEstados& vetor) {
    return vetor.elementos[vetor.tamanho - 1];
}

const EstadoJogo& vetorEstadosObterUltimo(const VetorEstados& vetor) {
    return vetor.elementos[vetor.tamanho - 1];
}

void vetorEstadosLiberarMemoria(VetorEstados& vetor) {
    vetorEstadosLimpar(vetor);
    delete[] vetor.elementos;
    vetor.elementos = nullptr;
    vetor.capacidade = 0;
    vetor.tamanho = 0;
}

// ---------------------------------------------------------------- Funções Utilitárias

static bool ehCartaVermelha(const Carta& carta) {
    return carta.naipe == 1 || carta.naipe == 2;
}

static char converterParaMinusculo(char caractere) {
    if (caractere >= 'A' && caractere <= 'Z') return caractere + ('a' - 'A');
    return caractere;
}

static size_t obterMaiorValor(size_t valor_a, size_t valor_b) {
    return (valor_a > valor_b) ? valor_a : valor_b;
}

static bool compararStrings(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return false;
        ++str1; ++str2;
    }
    return *str1 == *str2;
}

static int converterStringParaInt(const char* texto, bool& conversao_ok) {
    conversao_ok = false;
    if (!texto || !*texto) return 0;
    int resultado = 0, idx = 0;
    while (texto[idx] != '\0') {
        if (texto[idx] < '0' || texto[idx] > '9') return 0;
        resultado = resultado * 10 + (texto[idx] - '0');
        ++idx;
    }
    conversao_ok = true;
    return resultado;
}

static unsigned long converterStringParaUnsigned(const char* texto, bool& conversao_ok) {
    conversao_ok = false;
    if (!texto || !*texto) return 0;
    unsigned long resultado = 0;
    int idx = 0;
    while (texto[idx] != '\0') {
        if (texto[idx] < '0' || texto[idx] > '9') return 0;
        resultado = resultado * 10 + (texto[idx] - '0');
        ++idx;
    }
    conversao_ok = true;
    return resultado;
}

// ---------------------------------------------------------------- Lógica do Jogo

static const char* SIMBOLOS_NAIPES[4] = {"\u2663", "\u2666", "\u2665", "\u2660"};
static const char* SLOT_VAZIO = "[ ]";
static const char* ESPACO_BRANCO = "    ";

static void imprimirTextoCarta(const Carta& carta) {
    static const char* NOMES_VALORES[14] = {"", " A", " 2", " 3", " 4", " 5", " 6",
                                            " 7", " 8", " 9", "10", " J", " Q", " K"};
    if (ehCartaVermelha(carta)) {
        cout << "\033[31m" << NOMES_VALORES[carta.valor] << SIMBOLOS_NAIPES[carta.naipe] << "\033[0m";
    } else {
        cout << NOMES_VALORES[carta.valor] << SIMBOLOS_NAIPES[carta.naipe];
    }
}

static bool podeEmpilharNaColuna(const Carta& carta_movida, const Carta& carta_destino) {
    return carta_destino.valor == carta_movida.valor + 1 && ehCartaVermelha(carta_movida) != ehCartaVermelha(carta_destino);
}

static Posicao interpretarPosicao(const char* texto) {
    Posicao pos;
    if (!texto || texto[0] == '\0' || texto[1] != '\0') return pos;
    char caractere = converterParaMinusculo(texto[0]);
    if (caractere >= '1' && caractere <= '8') {
        pos.tipo = Posicao::Coluna;
        pos.indice = caractere - '1';
    } else if (caractere >= 'a' && caractere <= 'd') {
        pos.tipo = Posicao::Celula;
        pos.indice = caractere - 'a';
    } else if (caractere == 'f') {
        pos.tipo = Posicao::Fundacao;
    }
    return pos;
}

static bool podeIrParaFundacao(const EstadoJogo& estado, const Carta& carta) {
    return estado.fundacoes[carta.naipe] == carta.valor - 1;
}

static bool ehCartaSeguraParaFundacao(const EstadoJogo& estado, const Carta& carta) {
    if (carta.valor <= 2) return true;
    int naipe_oposto_1 = ehCartaVermelha(carta) ? 0 : 1; // paus / ouros
    int naipe_oposto_2 = ehCartaVermelha(carta) ? 3 : 2; // espadas / copas
    return estado.fundacoes[naipe_oposto_1] >= carta.valor - 1 && 
           estado.fundacoes[naipe_oposto_2] >= carta.valor - 1;
}

static int calcularLimiteSupermovimento(const EstadoJogo& estado, bool coluna_destino_esta_vazia) {
    int celulas_livres_vazias = 0;
    for (int cel_idx = 0; cel_idx < 4; ++cel_idx) {
        if (!estado.celulas_livres[cel_idx].esta_ocupada) ++celulas_livres_vazias;
    }
    int colunas_vazias = 0;
    for (int col_idx = 0; col_idx < 8; ++col_idx) {
        if (vetorCartasEstaVazio(estado.colunas[col_idx])) ++colunas_vazias;
    }
    if (coluna_destino_esta_vazia && colunas_vazias > 0) {
        --colunas_vazias;
    }
    return (celulas_livres_vazias + 1) * (1 << colunas_vazias);
}

static void iniciarNovoJogo(EstadoJogo& estado_atual, VetorEstados& historico, unsigned semente) {
    liberarMemoriaEstado(estado_atual);
    vetorEstadosLimpar(historico);

    VetorCartas baralho;
    for (int naipe = 0; naipe < 4; ++naipe) {
        for (int valor = 1; valor <= 13; ++valor) {
            vetorCartasAdicionar(baralho, {valor, naipe});
        }
    }

    mt19937 gerador_aleatorio(semente);
    for (size_t idx = vetorCartasObterTamanho(baralho) - 1; idx > 0; --idx) {
        uniform_int_distribution<size_t> distribuicao(0, idx);
        size_t idx_sorteado = distribuicao(gerador_aleatorio);
        Carta temp = vetorCartasObterEm(baralho, idx);
        vetorCartasObterEm(baralho, idx) = vetorCartasObterEm(baralho, idx_sorteado);
        vetorCartasObterEm(baralho, idx_sorteado) = temp;
    }

    for (size_t idx = 0; idx < vetorCartasObterTamanho(baralho); ++idx) {
        vetorCartasAdicionar(estado_atual.colunas[idx % 8], vetorCartasObterEm(baralho, idx));
    }
    vetorCartasLiberarMemoria(baralho);
}

static bool verificarVitoria(const EstadoJogo& estado) {
    for (int naipe_idx = 0; naipe_idx < 4; ++naipe_idx) {
        if (estado.fundacoes[naipe_idx] != 13) return false;
    }
    return true;
}

static bool desfazerJogada(EstadoJogo& estado_atual, VetorEstados& historico) {
    if (vetorEstadosEstaVazio(historico)) return false;
    liberarMemoriaEstado(estado_atual);
    copiarEstadoJogo(estado_atual, vetorEstadosObterUltimo(historico));
    vetorEstadosRemoverUltimo(historico);
    return true;
}

static bool executarMovimento(EstadoJogo& estado_atual, VetorEstados& historico, Posicao origem, Posicao destino, int quantidade_cartas, const char*& mensagem_erro) {
    if (origem.tipo == Posicao::Invalida || destino.tipo == Posicao::Invalida) {
        mensagem_erro = "Local invalido. Use colunas 1-8, free cells a-d ou f (fundacao).";
        return false;
    }
    if (origem.tipo == Posicao::Fundacao) {
        mensagem_erro = "Nao e possivel tirar cartas da fundacao.";
        return false;
    }
    if (origem.tipo == destino.tipo && origem.indice == destino.indice) {
        mensagem_erro = "Origem e destino sao o mesmo local.";
        return false;
    }
    if (quantidade_cartas < 1) {
        mensagem_erro = "A quantidade de cartas deve ser pelo menos 1.";
        return false;
    }

    VetorCartas cartas_em_movimento;
    if (origem.tipo == Posicao::Celula) {
        if (!estado_atual.celulas_livres[origem.indice].esta_ocupada) {
            mensagem_erro = "Essa free cell esta vazia.";
            return false;
        }
        if (quantidade_cartas != 1) {
            mensagem_erro = "De uma free cell sai apenas 1 carta.";
            return false;
        }
        vetorCartasAdicionar(cartas_em_movimento, estado_atual.celulas_livres[origem.indice].carta);
    } else {
        const auto& coluna_origem = estado_atual.colunas[origem.indice];
        if (vetorCartasEstaVazio(coluna_origem)) {
            mensagem_erro = "Essa coluna esta vazia.";
            return false;
        }
        if (quantidade_cartas > static_cast<int>(vetorCartasObterTamanho(coluna_origem))) {
            mensagem_erro = "A coluna nao tem tantas cartas.";
            return false;
        }
        size_t inicio_idx = vetorCartasObterTamanho(coluna_origem) - quantidade_cartas;
        for (size_t idx = inicio_idx; idx < vetorCartasObterTamanho(coluna_origem); ++idx) {
            vetorCartasAdicionar(cartas_em_movimento, vetorCartasObterEm(coluna_origem, idx));
        }
        for (int idx = 0; idx + 1 < quantidade_cartas; ++idx) {
            if (!podeEmpilharNaColuna(vetorCartasObterEm(cartas_em_movimento, idx + 1), vetorCartasObterEm(cartas_em_movimento, idx))) {
                mensagem_erro = "Essas cartas nao formam uma sequencia (cores alternadas, ranks decrescentes).";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
        }
    }

    switch (destino.tipo) {
        case Posicao::Coluna: {
            const auto& coluna_destino = estado_atual.colunas[destino.indice];
            if (!vetorCartasEstaVazio(coluna_destino) && !podeEmpilharNaColuna(vetorCartasObterEm(cartas_em_movimento, 0), vetorCartasObterUltimo(coluna_destino))) {
                mensagem_erro = "Movimento invalido: a carta precisa ser de cor oposta e 1 rank abaixo.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            int limite_movimento = calcularLimiteSupermovimento(estado_atual, vetorCartasEstaVazio(coluna_destino));
            if (quantidade_cartas > limite_movimento) {
                mensagem_erro = "Quantidade de cartas excede o limite movimentavel com as free cells/colunas livres.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            break;
        }
        case Posicao::Celula:
            if (quantidade_cartas != 1) {
                mensagem_erro = "Uma free cell guarda apenas 1 carta.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            if (estado_atual.celulas_livres[destino.indice].esta_ocupada) {
                mensagem_erro = "Essa free cell ja esta ocupada.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            break;
        case Posicao::Fundacao:
            if (quantidade_cartas != 1) {
                mensagem_erro = "Para a fundacao vai 1 carta por vez.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            if (!podeIrParaFundacao(estado_atual, vetorCartasObterEm(cartas_em_movimento, 0))) {
                mensagem_erro = "Essa carta ainda nao pode ir para a fundacao.";
                vetorCartasLiberarMemoria(cartas_em_movimento);
                return false;
            }
            break;
        default:
            vetorCartasLiberarMemoria(cartas_em_movimento);
            return false;
    }

    EstadoJogo captura_historico;
    copiarEstadoJogo(captura_historico, estado_atual);
    vetorEstadosAdicionar(historico, captura_historico);
    liberarMemoriaEstado(captura_historico);

    if (origem.tipo == Posicao::Celula)
        estado_atual.celulas_livres[origem.indice].esta_ocupada = false;
    else
        vetorCartasRedimensionar(estado_atual.colunas[origem.indice], vetorCartasObterTamanho(estado_atual.colunas[origem.indice]) - quantidade_cartas);

    switch (destino.tipo) {
        case Posicao::Coluna:
            for (size_t idx = 0; idx < vetorCartasObterTamanho(cartas_em_movimento); ++idx) {
                vetorCartasAdicionar(estado_atual.colunas[destino.indice], vetorCartasObterEm(cartas_em_movimento, idx));
            }
            break;
        case Posicao::Celula:
            estado_atual.celulas_livres[destino.indice].carta = vetorCartasObterEm(cartas_em_movimento, 0);
            estado_atual.celulas_livres[destino.indice].esta_ocupada = true;
            break;
        case Posicao::Fundacao:
            estado_atual.fundacoes[vetorCartasObterEm(cartas_em_movimento, 0).naipe]++;
            break;
        default:
            break;
    }

    vetorCartasLiberarMemoria(cartas_em_movimento);
    return true;
}

static void salvarEstadoNoHistoricoUmaVez(EstadoJogo& estado_atual, VetorEstados& historico, bool& salvo_com_sucesso) {
    if (!salvo_com_sucesso) {
        EstadoJogo captura_historico;
        copiarEstadoJogo(captura_historico, estado_atual);
        vetorEstadosAdicionar(historico, captura_historico);
        liberarMemoriaEstado(captura_historico);
        salvo_com_sucesso = true;
    }
}

static int executarMovimentoAutomatico(EstadoJogo& estado_atual, VetorEstados& historico) {
    int total_cartas_movidas = 0;
    bool estado_salvo = false;
    bool houve_progresso = true;

    while (houve_progresso) {
        houve_progresso = false;
        for (int cel_idx = 0; cel_idx < 4; ++cel_idx) {
            auto& celula = estado_atual.celulas_livres[cel_idx];
            if (celula.esta_ocupada && podeIrParaFundacao(estado_atual, celula.carta) && ehCartaSeguraParaFundacao(estado_atual, celula.carta)) {
                salvarEstadoNoHistoricoUmaVez(estado_atual, historico, estado_salvo);
                estado_atual.fundacoes[celula.carta.naipe]++;
                celula.esta_ocupada = false;
                ++total_cartas_movidas;
                houve_progresso = true;
            }
        }
        for (int col_idx = 0; col_idx < 8; ++col_idx) {
            auto& coluna = estado_atual.colunas[col_idx];
            if (!vetorCartasEstaVazio(coluna) && podeIrParaFundacao(estado_atual, vetorCartasObterUltimo(coluna)) && ehCartaSeguraParaFundacao(estado_atual, vetorCartasObterUltimo(coluna))) {
                salvarEstadoNoHistoricoUmaVez(estado_atual, historico, estado_salvo);
                estado_atual.fundacoes[vetorCartasObterUltimo(coluna).naipe]++;
                vetorCartasRemoverUltimo(coluna);
                ++total_cartas_movidas;
                houve_progresso = true;
            }
        }
    }
    return total_cartas_movidas;
}

static void desenharTabuleiro(const EstadoJogo& estado_atual, unsigned semente, size_t total_jogadas) {
    cout << "\n  FREECELL   (semente " << semente << " | jogadas " << total_jogadas << ")\n\n";

    cout << "    a     b     c     d           \u2663     \u2666     \u2665     \u2660\n  ";
    for (int cel_idx = 0; cel_idx < 4; ++cel_idx) {
        if (estado_atual.celulas_livres[cel_idx].esta_ocupada) {
            imprimirTextoCarta(estado_atual.celulas_livres[cel_idx].carta);
        } else {
            cout << SLOT_VAZIO;
        }
        cout << "   ";
    }
    cout << "     ";
    for (int naipe_idx = 0; naipe_idx < 4; ++naipe_idx) {
        if (estado_atual.fundacoes[naipe_idx] > 0) {
            imprimirTextoCarta({estado_atual.fundacoes[naipe_idx], naipe_idx});
            cout << "   ";
        } else {
            cout << SLOT_VAZIO << "   ";
        }
    }
    cout << "\n\n  ";

    for (int col_idx = 0; col_idx < 8; ++col_idx) cout << " " << (col_idx + 1) << "     ";
    cout << "\n";

    size_t altura_maxima_coluna = 0;
    for (int col_idx = 0; col_idx < 8; ++col_idx) {
        altura_maxima_coluna = obterMaiorValor(altura_maxima_coluna, vetorCartasObterTamanho(estado_atual.colunas[col_idx]));
    }

    for (size_t lin_idx = 0; lin_idx < altura_maxima_coluna; ++lin_idx) {
        cout << "  ";
        for (int col_idx = 0; col_idx < 8; ++col_idx) {
            if (lin_idx < vetorCartasObterTamanho(estado_atual.colunas[col_idx])) {
                imprimirTextoCarta(vetorCartasObterEm(estado_atual.colunas[col_idx], lin_idx));
            } else {
                cout << ESPACO_BRANCO;
            }
            cout << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// ---------------------------------------------------------------- Interface e Main

static void exibirAjuda() {
    cout <<
        "\nComo jogar\n"
        "  Objetivo: levar todas as cartas para as 4 fundacoes (A ate K, por naipe).\n"
        "  Nas colunas, empilhe em ordem decrescente com cores alternadas.\n\n"
        "Locais: colunas 1-8 | free cells a-d | f = fundacao\n\n"
        "Comandos\n"
        "  3 5        move a carta do topo da coluna 3 para a coluna 5\n"
        "  35         atalho para o mesmo movimento\n"
        "  3 a        coluna 3 -> free cell a\n"
        "  a 5        free cell a -> coluna 5\n"
        "  3 f        coluna 3 -> fundacao (o naipe e escolhido automaticamente)\n"
        "  3 5 4      move uma sequencia de 4 cartas da coluna 3 para a 5\n"
        "  auto       manda para a fundacao as cartas seguras\n"
        "  u          desfazer\n"
        "  r          reiniciar este jogo\n"
        "  n [semente] novo jogo (com semente opcional, para repetir um jogo)\n"
        "  h          ajuda\n"
        "  q          sair\n\n";
}

static int dividirLinhaEmTokens(char* linha_comando, char tokens[3][128]) {
    int total_tokens = 0, char_idx = 0;
    while (linha_comando[char_idx] != '\0' && total_tokens < 3) {
        while (linha_comando[char_idx] == ' ' || linha_comando[char_idx] == '\t' || 
               linha_comando[char_idx] == '\n' || linha_comando[char_idx] == '\r') {
            ++char_idx;
        }
        if (linha_comando[char_idx] == '\0') break;

        int token_char_idx = 0;
        while (linha_comando[char_idx] != '\0' && linha_comando[char_idx] != ' ' && 
               linha_comando[char_idx] != '\t' && linha_comando[char_idx] != '\n' && 
               linha_comando[char_idx] != '\r') {
            if (token_char_idx < 127) {
                tokens[total_tokens][token_char_idx++] = linha_comando[char_idx];
            }
            ++char_idx;
        }
        tokens[total_tokens][token_char_idx] = '\0';
        total_tokens++;
    }
    return total_tokens;
}

int main(int argc, char** argv) {
    random_device dispositivo_aleatorio;
    unsigned semente = dispositivo_aleatorio() % 1000000;
    if (argc > 1) {
        bool conversao_ok = false;
        unsigned long semente_parametro = converterStringParaUnsigned(argv[1], conversao_ok);
        if (conversao_ok) {
            semente = static_cast<unsigned>(semente_parametro);
        } else {
            cerr << "Semente invalida, usando uma aleatoria.\n";
        }
    }

    EstadoJogo estado_atual;
    VetorEstados historico_jogadas;

    iniciarNovoJogo(estado_atual, historico_jogadas, semente);
    cout << "Bem-vindo ao FreeCell! Digite 'h' para ver os comandos.\n";
    desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));

    char linha_comando[256];
    while (true) {
        cout << "> " << flush;
        if (!cin.getline(linha_comando, sizeof(linha_comando))) break;

        char tokens_comando[3][128];
        int total_tokens = dividirLinhaEmTokens(linha_comando, tokens_comando);
        if (total_tokens == 0) continue;

        char comando_principal[128];
        int char_idx = 0;
        for (; tokens_comando[0][char_idx] != '\0'; ++char_idx) {
            comando_principal[char_idx] = converterParaMinusculo(tokens_comando[0][char_idx]);
        }
        comando_principal[char_idx] = '\0';

        if (compararStrings(comando_principal, "q") || compararStrings(comando_principal, "quit") || compararStrings(comando_principal, "sair")) {
            break;
        }

        if (compararStrings(comando_principal, "h") || compararStrings(comando_principal, "help") || compararStrings(comando_principal, "ajuda")) {
            exibirAjuda();
            continue;
        }
        if (compararStrings(comando_principal, "u") || compararStrings(comando_principal, "undo")) {
            if (desfazerJogada(estado_atual, historico_jogadas)) {
                desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));
            } else {
                cout << "Nada para desfazer.\n";
            }
            continue;
        }
        if (compararStrings(comando_principal, "r")) {
            iniciarNovoJogo(estado_atual, historico_jogadas, semente);
            desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));
            continue;
        }
        if (compararStrings(comando_principal, "n") || compararStrings(comando_principal, "novo")) {
            unsigned nova_semente = dispositivo_aleatorio() % 1000000;
            if (total_tokens > 1) {
                bool conversao_ok = false;
                unsigned long semente_lida = converterStringParaUnsigned(tokens_comando[1], conversao_ok);
                if (conversao_ok) {
                    nova_semente = static_cast<unsigned>(semente_lida);
                } else {
                    cout << "Semente invalida.\n";
                    continue;
                }
            }
            semente = nova_semente;
            iniciarNovoJogo(estado_atual, historico_jogadas, semente);
            desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));
            continue;
        }
        if (compararStrings(comando_principal, "auto")) {
            int cartas_movidas = executarMovimentoAutomatico(estado_atual, historico_jogadas);
            desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));
            if (cartas_movidas == 0) {
                cout << "Nenhuma carta segura para mandar a fundacao.\n";
            }
            if (verificarVitoria(estado_atual)) {
                cout << "*** PARABENS, VOCE VENCEU! *** Digite 'n' para um novo jogo.\n";
            }
            continue;
        }

        if (total_tokens == 1 && tokens_comando[0][0] != '\0' && tokens_comando[0][1] != '\0' && tokens_comando[0][2] == '\0') {
            tokens_comando[1][0] = tokens_comando[0][1];
            tokens_comando[1][1] = '\0';
            tokens_comando[0][1] = '\0';
            total_tokens = 2;
        }

        if (total_tokens < 2 || total_tokens > 3) {
            cout << "Comando nao reconhecido. Digite 'h' para ajuda.\n";
            continue;
        }

        int quantidade_cartas = 1;
        if (total_tokens == 3) {
            bool conversao_ok = false;
            quantidade_cartas = converterStringParaInt(tokens_comando[2], conversao_ok);
            if (!conversao_ok) {
                cout << "Quantidade invalida.\n";
                continue;
            }
        }

        const char* mensagem_erro = nullptr;
        Posicao origem = interpretarPosicao(tokens_comando[0]);
        Posicao destino = interpretarPosicao(tokens_comando[1]);

        if (executarMovimento(estado_atual, historico_jogadas, origem, destino, quantidade_cartas, mensagem_erro)) {
            desenharTabuleiro(estado_atual, semente, vetorEstadosObterTamanho(historico_jogadas));
            if (verificarVitoria(estado_atual)) {
                cout << "*** PARABENS, VOCE VENCEU! *** Digite 'n' para um novo jogo.\n";
            }
        } else {
            if (mensagem_erro) {
                cout << mensagem_erro << "\n";
            }
        }
    }

    liberarMemoriaEstado(estado_atual);
    vetorEstadosLiberarMemoria(historico_jogadas);

    cout << "Ate a proxima!\n";
    return 0;
}