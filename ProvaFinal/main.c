#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maxprodutos = 100, opcao = 0, codigoproduto, auxiliar;
    int codigo[maxprodutos], produtoscadastrados = 0;
    float precocompra[maxprodutos], precovenda[maxprodutos];

    do
    {
        printf ("\n==========Menu Principal==========\n");
        printf ("1- Cadastrar produto\n");
        printf ("2- Pesquisar produto\n");
        printf ("3- Alterar preco de venda\n");
        printf ("4- Lista de produtos\n");
        printf ("5- Sair do sistema\n");
        printf ("O que voce quer fazer? ");
        scanf ("%d", &opcao);

        switch (opcao)
        {
            case 1:
                if (produtoscadastrados < maxprodutos)
                {
                    printf ("\n----> Cadastro de produtos\n");
                    printf ("Informe o codigo do produto: ");
                    scanf ("%d", &codigoproduto);
                    printf ("Informe o preco de compra do produto: ");
                    scanf ("%f", &precocompra[produtoscadastrados]);
                    printf ("Informe o preco de venda: ");
                    scanf ("%f", &precovenda[produtoscadastrados]);

                    codigo [produtoscadastrados] = codigoproduto;
                    produtoscadastrados++;
                }
                break;

            case 2:
                printf ("\n----> Pesquisar produto\n");
                printf ("Informe o codigo do produto: ");
                scanf ("%d", &codigoproduto);

                auxiliar = -1;

                for (int i = 0; i < produtoscadastrados; i++)
                {
                    if (codigo[i] == codigoproduto)
                    {
                        printf ("Produto: %d\n", codigo[i]);
                        printf ("Preco de compra do produto: %.2f\n", precocompra[i]);
                        printf ("Preco de venda do produto: %.2f\n", precovenda[i]);
                        auxiliar = i;
                    }
                }
                if (auxiliar < 0)
                    printf ("O produto nao esta cadastrado\n");
                break;

            case 3:
                printf ("\n----> Alterar preco de venda\n");
                printf ("Informe o codigo do produto: ");
                scanf ("%d", &codigoproduto);

                for (int i = 0; i < produtoscadastrados; i++)
                {
                    if (codigo[i] == codigoproduto)
                    {
                        printf ("Informe o novo preco de venda: ");
                        scanf ("%f", &precovenda[i]);
                        printf ("Preco de venda atualizado com sucesso\n");
                        auxiliar = i;
                    }
                }
                if (auxiliar < 0)
                    printf ("Produto nao encontrado\n");
                break;

            case 4:
                printf ("\n----> Lista de produtos\n");

                if (produtoscadastrados > 0)
                {
                    printf ("Codigo \tPreco de compra\tPreco de venda\n");
                    for (int i = 0; i < produtoscadastrados; i++)
                        {
                            printf ("%d     \t%.2f         \t%.2f\n", codigo[i], precocompra[i], precovenda[i]);
                        }
                }
                else
                {
                    printf ("Nenhum produto cadastrasdo\n");
                }
                break;
        }
    } while (opcao != 5);
    printf ("Fim do sistema.\n");
    return 0;
}
