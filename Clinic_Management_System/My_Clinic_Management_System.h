#ifndef CLINIC_MANAGEMENTSYSTEM_CONFIG_H_
#define CLINIC_MANAGEMENTSYSTEM_CONFIG_H_


#include "STD_Types.h"
#define PASSWORD 1234
#define NO_OF_SLOTS 5


struct Patient_Node *head = NULL;
u32 availableSlots =5;    // No.available slots
u32 arr[5] = {1,2,3,4,5};  //array of available slots
u32 i ;

           
struct Patient_Node
{
   u8 name[30];
   u8 gender[30];
   u32 id;
   u32 age;
   u32 slot;
   struct Patient_Node *next;
};
 
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   All Functions   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                 /* Select Mode (main)Function */

void SelectMode_Func(void);

                                 /* Admin Mode Functions */

void Admin_Mode(void);
void Admin_ChoiceFunc(void);
void AddPatient_Func(void);
void EditPatientInfo_Func(void);
void ReserveSlot_Func(void);
void CancelReservation_Func(void);

                                 /* User Mode Functions */
void User_Mode(void);
void ViewPatientInformation_Func(void);
void ViewPatientsReservations_Func (void);





#endif