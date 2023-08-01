#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int infinite_loop(void);

/**
 * main - Entry point for function to create 5 zombie processes
 * Return: infinite_while loop
 */
int main(void)
{
	pid_t PID;
	unsigned int i;

	while (i < 5)
	{
		PID = fork();
		if (PID == 0)
			exit(0);
		else
			printf("Zombie process created, PID: %d\n", PID);
		i++;
	}
	return (infinite_while());
}

/**
 * infinite_loop - create infinite sleep loop
 * Return: 0
 */
int infinite_loop(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
