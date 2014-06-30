///recebe os parametros: D, N, PM, PR

///gerar população inicial (vetor de binarios)

///calcular FITNESS de cada individuo

///ENQUANTO condição de parada não atingida {

    ///PARA i=1 até N {

        ///escolha aleatoriamente o indice de um individuo (que não seja o atual): s = rndint(1, N) com s diferente de i

        ///escolha aleatoriamente o indice de uma variavel (bit): j[rand] = rndint(1,D)

        ///solução teste y recebe x[i]

        ///PARA j=1 até D {

            ///SE rndreal(0,1) < PR ou j = j[rand] {

                ///{perturbação de y}

                ///SE rndreal(0,1) < PM {
                    ///{mutação}
                    ///InverterBit()
                ///}

                ///SENAO {
                    ///{crossover}
                    ///y[j] = x[sj]
                ///}

            ///}

        ///}

        ///Calcular fitness de y

        ///SE fit(y) > fit(x[i]) {
            ///{atualiza a solução corrente}
            ///x[i] recebe y
        ///}

    ///}

    ///encontrar melhor solução corrente de x[]

///}

///apresentar resultados
