#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n, x, y, num;
	bool prateleira[10000];

	while (scanf("%d", &n) != EOF)
	{

		for (int i = 0; i < 10001; i++)
		{
			prateleira[i] = false;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			for (int j = x; j <= y; j++)
			{
				prateleira[j] = true;
			}
		}

		scanf("%d", &num);
		bool encontrado = false;
		int contador = 0;
		int inicio, fim;
		for (int i = 1; i <= 10000; i++)
		{
			if (prateleira[i] && !encontrado && i == num)
			{
				encontrado = true;
				inicio = i;
				contador++;
			}
			else if (!prateleira[i] && encontrado)
			{
				fim = i + 1;
				inicio = inicio + 2;
				printf("%d encontrado de %d a %d\n", num, inicio, fim);
				encontrado = false;
				contador++;
			}
		}

		if (contador == 0)
		{
			printf("%d nao encontrado\n", num);
		}
	}

	return 0;
}
