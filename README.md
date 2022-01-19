# Biblioteca para operações nos Backup Registers do STM32

**Descrição da biblioteca:**<br>
Os *Backup Registers* são dez registradores de 16 bits usados para armazenar 20 bytes de dados do aplicativo do usuário quando a alimentação (Vdd) não está presente.
A biblioteca permite a fácil operação dos registradores de backup (*Backup registers*) do STM32, como escrita, leitura e apagamento.
Esta biblioteca também está documentada em [vídeo](https://youtu.be/B3UiPsuIEuk), além disso, um exemplo de aplicação pode ser baixado [aqui](https://github.com/delpitec/C_STM32_Youtube_Codigos/tree/BackupRegisterExemplo).

&nbsp;<br>

**Status do desenvolvimento:**<br>
✅ Concluído

&nbsp;<br> 
 
**Modo de utilização da biblioteca (passo-a-passo):**&nbsp;<br> 
1 - Criar um novo projeto na ferramenta STM32CubeIDE. Caso tenha dúvidas na criação do projeto, verifique aqui [como criar um projeto desde o início com a ferramenta STM32CubeIDE](https://www.youtube.com/watch?v=0UmISQhm_8k&t=338s);&nbsp;<br>
2 - Após criar o projeto, insira os [arquivos .h e .c deste repositório]()  nas seguintes pastas do projeto a seguir **(1)** e realize a inserção da seguinte linha de código no local mostrado na próxima imagem: **(2)**:
```ruby
#include "BackupRegister.h"
```
&nbsp;<br> 
![bkpureg](https://user-images.githubusercontent.com/58537514/136269552-282d4974-8fa5-4815-9de2-24d09ec0d030.png)

&nbsp;<br> 

3 - Realizar as operações desejadas através das funções a seguir, devidamente comentadas em *hard code*.
```ruby
	// Habilita escrita nos Backup registers
	void BKPREG_iniciar(void);
	
	// Desabilita escrita nos Backup registers
	void BKPREG_encerrar(void);
	
	// Escreve dado "Data" no endereço especificado em "BackupReg"
	void BKPREG_escrever(BkpregID BackupReg, uint32_t Data);
	
	// Retorna valor armazenado no endereço especificado em "BackupReg"
	uint32_t BKPREG_ler(BkpregID BackupReg);
	
	// Apaga todos os dados contidos nos backup registers
	void BKPREG_apagar_tudo(void);
	
	// Apaga dado contido no endereço especificado em "BackupReg"
	void BKPREG_apaga(uint32_t BackupReg);
```

&nbsp;<br> 

## Contact me:
💼[LinkedIn](https://br.linkedin.com/in/rafaeldelpino)&nbsp;&nbsp;&nbsp;
📹[Youtube](https://www.youtube.com/delpitec)&nbsp;&nbsp;&nbsp;
📸[Instagram](https://www.instagram.com/delpitec_/)&nbsp;&nbsp;&nbsp;
📧[E-mail](delpitec@gmail.com)&nbsp;&nbsp;&nbsp;
