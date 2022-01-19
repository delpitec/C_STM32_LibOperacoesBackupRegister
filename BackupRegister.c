/*
 *  BackupRegister.c
 *
 *  Created on: Mar 25, 2021
 *      Author: Rafael Del Pino
 */

#include"BackupRegister.h"

/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Habilita escrita nos registradores de backup register.
  *
  * @param1  :  Void
  *
  * @retval  :  Void
  */
void BKPREG_iniciar(void){

	RCC->APB1ENR   |=   0x18000000;		// Enable the power and backup interface clocks
	PWR->CR        |=   0x00000100;		// Access to RTC and Backup registers enabled;

}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Desabilita escrita nos registradores de backup register.
  *
  * @param1  :  Void
  *
  * @retval  :  Void
  */
void BKPREG_encerrar(void){

	RCC->APB1ENR   &=   ~(0x18000000);		// Enable the power and backup interface clocks
	PWR->CR        &=   ~(0x00000100);		// Access to RTC and Backup registers enabled;

}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Escreve dado @param1 no endereço especificado em @param2
  *
  * @param1  :  ID do endereço do backup register que se deseja escrever
  * @param2  :  Dado que se deseja armazenar no backup register
  * 
  * @retval  :  Void
  */
void BKPREG_escrever(BkpregID BackupReg, uint32_t Data)
{
	uint32_t tmp = 0U;

	tmp = (uint32_t)BKP_BASE;
	tmp += (BackupReg * 4U);

	*(__IO uint32_t *) tmp = (Data & BKP_DR1_D);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Retorna valor armazenado no ID do endereço do backup register que se deseja ler
  *
  * @param1  :  ID do endereço do backup register que se deseja ler
  * 
  * @retval  :  Void
  */
uint32_t BKPREG_ler(BkpregID BackupReg){
	  uint32_t backupregister = 0U;
	  uint32_t pvalue = 0U;

	  backupregister = (uint32_t)BKP_BASE;
	  backupregister += (BackupReg * 4U);

	  pvalue = (*(__IO uint32_t *)(backupregister)) & BKP_DR1_D;

	  return pvalue;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Apaga todos os dados contidos nos backup registers
  *
  * @param1  :  Void
  * 
  * @retval  :  Void
  */
void BKPREG_apagar_tudo(void){

	for(uint8_t BackupReg = 0; BackupReg <= RTC_BKP_NUMBER; BackupReg++){
		BKPREG_escrever(BackupReg, 0x0000);
	}

}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo  :  Apaga os dados contidos no ID do endereço do backup register que se deseja apagar
  *
  * @param1  :  ID do endereço do backup register que se deseja apagar
  * 
  * @retval  :  Void
  */
void BKPREG_apaga(uint32_t BackupReg){

	BKPREG_escrever(BackupReg, 0x0000);

}
/*----------------------------------------------------------------------------------------------------------------------------------*/

