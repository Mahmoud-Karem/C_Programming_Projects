/*
*
*########### Clinic_Management_System ############
*
* ###  Author : Mahmoud Karem Zamel
*
*
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "My_Clinic_Management_System.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Main_Function   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void SelectMode_Func(void)
{
    u32 Mode;
    printf("\n<<<<<<<<<<<<<<<<<<   Welcome To Clinic_Management_System   >>>>>>>>>>>>>>>>>>\n\n");
    printf("*** Please Choise Your Mode :- \n");
    printf("-----------------------------------------\n");
    printf("For Admin Mode press : 1\n");
    printf("For User Mode press : 2\n");

    scanf("%d",&Mode);
    printf("\n");


    switch(Mode)
    {
    case 1 :
        // Call The Admin Mode Function
        Admin_Mode();
        break;
    case 2 :
        // Call The User Mode Function
        User_Mode();
        break;
    default :
        /* Print A Message For The User To Re Enter The Right Choice */
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Right Mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");

    }

}




//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Admin Function   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Admin_Mode(void)
{
    u32 Pass;
    u32 Count=0;
    printf("<<<<<<<<<<<<<<<<<<   Welcome To Admin Mode   >>>>>>>>>>>>>>>>>>\n");
    printf("Please Enter Your Password :");
    scanf("%d",&Pass);
    if (Pass==PASSWORD)
    {
        Admin_ChoiceFunc();

    }
    else if (Pass!=PASSWORD)       // If the entered password is wrong
    {
        for (i=0; i<2; i++)        // Only 3 times again
        {

            // To Explain The Remaining times To The Admin

            if ( i < 1)

            {
                printf("Wrong Password ......... you have %d times\nPlease Enter Password Again : ", 2-i );
            }
            else
            {
                printf("This is the Last time Please Enter The Correct Password : ");
            }



            scanf("%d",&Pass);
            if (Pass==PASSWORD)// in case he enter correct passs in trial
            {
                Admin_ChoiceFunc();
            }
        }
        //to test the condition after the for loop
        if (Pass!=PASSWORD)
        {
            printf("Incorrect password for 3 times : Sorry No more tries :( ");
        }
    }

}

void Admin_ChoiceFunc(void)
{

    u32 Choice_Num;


    while(1)
    {
        printf("\nWelcome to Admin Mode Functions\n");
		printf("------------------------------------------------------------------\n");
        printf("1-Add New Patient Record \n");
        printf("2-Edit Patient Records \n");
        printf("3-Reserve A Slot With A doctor \n");
        printf("4-Cancel Reservation \n");
        printf("5-Return to the Select Mode Page \n");

        /* Scanning The Admin Required Choice */
        printf("Please Enter The Number That Represent Your Choice From This List :");
        scanf("%d",&Choice_Num);

        switch (Choice_Num)
        {

        case 1:
            printf("------------------------------------------------------------------\n");
			/* Call Add New Patient Informations Function To The Clinic Database */
            AddPatient_Func();
            break;

        case 2:
            printf("------------------------------------------------------------------\n");
			/* Call Edit Patient Informations Function In The Clinic Database */
            EditPatientInfo_Func();
            break;

        case 3:
            printf("------------------------------------------------------------------\n");
			/* Call Reserve Slot With A Doctor Function For Certain Patient  */
            ReserveSlot_Func();
            break;

        case 4:
            printf("------------------------------------------------------------------\n");
			/* Call Cancel The Reservation Of Doctor Function For Certain Patient */
            CancelReservation_Func();
            break;

        case 5:
            printf("------------------------------------------------------------------\n");
			/* Call The Select Mode Again To Return Back To The Select Mode Page Again */
            SelectMode_Func();
            break;
        default:
            printf("                     ********* Invalid Choice ********* \n");
            printf("             ********* Please Choose the right action ********* \n");
            break;
        }


    }


}




//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    All Admin Mode Functions    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void AddPatient_Func(void)
{
    if(availableSlots)
    {
        /* Create New Node Containing The New Patient Informations */
        struct Patient_Node *link = (struct Patient_Node*) malloc(sizeof(struct Patient_Node));

        /* Scanning The Patient Informations From The Admin */
        printf("                ********* Please Enter The Patient Informations ********* \n");
        printf("\n");
        printf("Patient Name : ");
        scanf("%s",&link->name);
        printf("\n");
        printf("Patient Age : ");
        scanf("%d",&link->age);
        printf("\n");
        printf("Patient Gender : ");
        scanf("%s",&link->gender);
        printf("\n");
        printf("Patient ID : ");
        scanf("%d",&link->id);
        printf("\n");

        /* Set The Intitial Value Of The Next Of The New Link Node To NULL */
        link->next = NULL;
        /* Check If There Is Already Node Exist Or Not*/
        if(head == NULL)
        {
            /* As The Head Pointer Still NULL And There Is No Linked List So Create A New Node In The Linked List */
            head = link;
        }
        else
        {
            struct Patient_Node *Ptr1,*Ptr2;
            Ptr1 = Ptr2 = head;
            /*Check If the Input ID Is Already Exist Or Not And If it Exists Re Enter A New ID */
            while(Ptr2 != NULL)
            {
                if(link->id == Ptr2->id)
                {
                    printf("\nThis ID already exists.\n"
                           "Please Enter New ID : ");
                    scanf("%d",&link->id);
                    Ptr2 = head;
                }
                Ptr1 = Ptr2;
                Ptr2 = Ptr2->next;
            }
            Ptr1->next = link;
        }
    }
    /* If There Is No Availible Slots For Doctor Reservations Print A Message
     *          For The Admin That There is No Availible Slots               */
    else
    {
        printf("Sorry There Are No Available Slots \n");
    }

}



void EditPatientInfo_Func()
{
    /*Create A Local Pointer To Move On All The Nodes And Search
     *    For The Right ID Of The Patient To Edit His/Her Informations */
    struct Patient_Node *Ptr1=head;
    u32 ID;
    u32 count=0;
    printf("\nPlease Enter the ID of the patient that you want to change His/Her Information : ");
    scanf("%d",&ID);
    /* Search For The Patient ID That You Want To Edit His/Her Informations */
    while(Ptr1->next != NULL)
    {
        if(ID == Ptr1->id)
        {
            /* Once You Find The Patient ID Edit This Patient Informations By Entering His/Her Information Again */
            count=1;
            printf("\n");
            printf("Please Enter the New Patient Name : ");
            scanf("%s",&Ptr1->name);
            printf("\n");
            printf("Please Enter the New patient age : ");
            scanf("%d",&Ptr1->age);
            printf("\n");
            printf("Please Enter the New patient gender : ");
            scanf("%s",&Ptr1->gender);
            printf("\n");
            break;
        }
        Ptr1 = Ptr1->next;
    }
    /* If You Didn't Find The Patient ID Print A message For The User To Re Enter The Right ID */
    if (count == 0)
    {
        printf("                                ********* Invalid ID ************ \n");
        printf("If you still want to edit a patient info choose Edit patient Informations from the list again \n");
        printf("-------------------------------------------------------------------------------------------------\n");

    }

}


void ReserveSlot_Func(void)
{
    /*Create A Local Pointer To Move On All The Patients Nodes And Check The ID Until Finding The Requred Patient Node
     *  To Reserve A Slot For The Required Patient */
    struct Patient_Node* Ptr1;
    u32 i, j =0;
    u32 ID;
    Ptr1 = head;

    /*Check if there is linked list with patients data or not */
    if(Ptr1 == NULL)
    {
        printf("There are no patients In The Database \n");
    }
    /*If there is Database with Patients Info So Scan the ID of the Patient That Want
      *  to reserve A Slot with A Doctor                                              */
    else
    {
        printf("Please Enter The Patient ID That You Want To Make a Reservation : ");
        scanf("%d",&ID);
        printf("\n");
        /* Move The Ptr1 On All the Node Until You Find The Required Patient ID*/
        while(Ptr1!= NULL)
        {
            /*If You Find The Required Patient ID Then Print All The Availible Slots Timings */
            if(ID == Ptr1->id)
            {
                for(i=1; i<= NO_OF_SLOTS; i++,j++)
                {
                    switch(arr[j])
                    {
                    case 1 :
                        printf("1- From 2:00 PM To 2:30 PM \n");
                        break;

                    case 2 :
                        printf("2- From 2:30 PM To 3:00 PM \n");
                        break;

                    case 3 :
                        printf("3- From 3:00 PM To 3:30 PM \n");
                        break;

                    case 4 :
                        printf("4- From 4:00 PM To 4:30 PM \n");
                        break;

                    case 5 :
                        printf("5- From 4:30 PM To 5:00 PM \n");
                        break;
                    }
                }
                /* Choose The Slot That You Want To Reserve And Delete This Slot From The Availible Slots For The Upcoming Reservations */
                printf("Please Select The Slot That You Want To Reserve : ");
                scanf("%d",&Ptr1->slot);
                arr[Ptr1->slot-1] = 0;
                availableSlots--;
                return;
            }
            else
            {
                Ptr1 = Ptr1->next;
            }
        }
        /* If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf("Incorrect ID Please Re Enter The Right ID : \n");
    }
}


void CancelReservation_Func(void)
{
    struct Patient_Node* Ptr1;
    u32 ID;
    Ptr1 = head;
    /* Check If There Is Patient Informations In The Database Or Not If Not Print This Message For The Admin */
    if(Ptr1 == NULL)
    {
        printf("There are no patients In The Database \n");
    }
    /* If There Is Patient Informations In The Database Ask The Admin To Enter The ID
     *        Of The Patient That Want To Cancel A Reservation                          */
    else
    {
        printf("Please Enter The Patient ID That you want to Cancel The Reservation : ");
        scanf("%d",&ID);
        /* Make A Loop Until You Find The Node That Contains The Same ID Of The Required Patient
         *     Then Cancel The Reservation                                                   */
        while(Ptr1!= NULL)
        {
            if(Ptr1->id == ID)
            {
                arr[Ptr1->slot-1] = Ptr1->slot;
                availableSlots++;
                return;
            }
            else
            {
                /* Set The Pointer To The Following Node To Check For The ID Till You Find */
                Ptr1 = Ptr1->next;
            }
        }
        /*If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf(" Incorrect ID Please Re Enter The Right ID :\n");
    }
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    User Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void User_Mode(void)
{
    printf("                                ********** User Mode Window ********** \n");
    u32 ch;
    while(1)
    {
        /* Ask The User To Enter The Required Choice */
        printf("1- View Patient Informations \n");
        printf("2- View Today Reservations \n");
        printf("3- Return To The Select Mode Page \n");
        printf("Please Enter The Number That Represent Your Choice From This List :");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1 :
            printf("------------------------------------------------------------------\n");
			/* Call The View Patient Informations Function */
            ViewPatientInformation_Func();
            break;

        case 2 :
            printf("------------------------------------------------------------------\n");
			/* Call The View Reservations Function */
            ViewPatientsReservations_Func();
            break;

        case 3 :
            printf("------------------------------------------------------------------\n");
			/* Call The Select Mode Functions To Return Back To The Select Mode Menu */
            SelectMode_Func();
            break;

        /*If The User Enter Wrong Choice Print A message To Re Choose The Right Action*/
        default :
            printf("                     ********* Invalid Choice ********* \n");
            printf("             ********* Please Choose The Right Action ********* \n");
            break;
        }
    }
}



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    All User Mode Functions    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void ViewPatientInformation_Func(void)
{
    /* Create A Pointer To Move On All The Patients Nodes To Print Every Patient Node Informations*/
    struct Patient_Node *Ptr1;
    u32 ID;
    Ptr1 = head;
    if(Ptr1 == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("There are no patients.\n");
    }
    else
    {
        printf("Enter patient ID : ");
        scanf("%d",&ID);
        /*Make A Loop On All The Nodes And Print Every Patient Informations */
        while(Ptr1!= NULL)
        {
            if(ID == Ptr1->id)
            {
                printf("Patient Name : %s",Ptr1->name);
                printf("\n");
                printf("Patient Gender : %s",Ptr1->gender);
                printf("\n");
                printf("Patient Age : %d",Ptr1->age);
                printf("\n");
                printf("Patient ID : %d",Ptr1->id);
                printf("\n");
                return;
            }
            else
            {
                Ptr1 = Ptr1->next;
            }
        }
        /*If The User Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf("Incorrect ID Please Re Enter The Right ID : \n");
    }
}



void ViewPatientsReservations_Func(void)
{
    /* Create A Pointer To Move On All The Patients Nodes To Print All The Patients Reservations  */
    struct Patient_Node *Ptr1;
    u32 slot;
    Ptr1 = head;
    if(Ptr1 == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
    else
    {
        /* Print All The Reservations Of All The Patients */
        printf("ID: reservation slot:\n");
        while(Ptr1!= NULL)
        {
            switch(Ptr1->slot)
            {
            case 1 :
                printf("%d   2:00 PM : 2:30 PM.\n",Ptr1->id);
                break;

            case 2 :
                printf("%d   2:30 PM : 3:00 PM.\n",Ptr1->id);
                break;

            case 3 :
                printf("%d   3:00 PM : 3:30 PM.\n",Ptr1->id);
                break;

            case 4 :
                printf("%d   4:00 PM : 4:30 PM.\n",Ptr1->id);
                break;

            case 5 :
                printf("%d   4:30 PM : 5:00 PM.\n",Ptr1->id);
                break;

            default :
                break;
            }
            Ptr1 = Ptr1->next;
        }
    }
}

int main(void)
{
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
    /* Call The Select Mode Functions */
    SelectMode_Func();


    return 0;
}

