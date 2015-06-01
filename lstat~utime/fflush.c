#include <stdio.h>

main()
{
	char *prompt="Prompt>>";
	char command[80];
	for(;;)
	{
		fputs(prompt,stdout);
		if(fgets(command,sizeof(command),stdin)==NULL)
			break;
		system(command);
	}
	fprintf(stdout,"Good bye...");
	fflush(stdout);
	system("clear");
}
