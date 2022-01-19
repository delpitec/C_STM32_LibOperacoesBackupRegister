/*
 * BackupRegister.h
 *
 *  Created on: Mar 25, 2021
 *      Author: Rafael
 */

#ifndef INC_BACKUPREGISTER_H_
#define INC_BACKUPREGISTER_H_

	#define RTC_BKP_NUMBER           10

	#include <stdint.h>
	#include <stm32f103xb.h>

	typedef enum{
		DR1 = 1, DR2, DR3, DR4, DR5, DR6, DR7, DR8, DR9, DR10
	}BkpregID;

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


#endif /* INC_BACKUPREGISTER_H_ */
