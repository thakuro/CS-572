#include<stdio.h>
#include<string.h>


int main (int argc, char **argv)

{
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;

    
   unsigned int l1_Cache_eax;
   unsigned int l1_Cache_ebx;
   unsigned int l1_Cache_ecx;
   unsigned int l1_Cache_edx;
   unsigned int cpu_family_eax;
   unsigned int cpu_family_ebx;
   unsigned int cpufreq_eax;
   unsigned int cpufreq_ebx;
   unsigned int cpufreq_ecx;
   unsigned int physicaladdwidth_eax;
unsigned int physicaladdwidth_ebx;
unsigned int physicaladdwidth_ecx;
unsigned int physicaladdwidth_edx;
unsigned int memhie_eax;
unsigned int memhie_ebx;
unsigned int memhie_ecx;
unsigned int memhie_edx;

//vendort id//

char vendor[13];
	
	eax = 0x00;
        ebx = 0x00;
        ecx = 0x00;
        edx = 0x00;

	asm volatile (
	                     "cpuid;"
	                     : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
	                     : "a"(eax)
	                     );
	
	
	memcpy(vendor, (char*)&ebx, 4);
	memcpy(vendor + 4, (char*)&edx, 4);
	memcpy(vendor + 8, (char*)&ecx, 4);
	vendor[12] = 0;

	printf("%s\n", vendor);

//vendorid end//
	
	

//  L1 Data Cache Size and TLB start //
   
        eax = 0x02;
        ebx = 0x00;
        ecx = 0x00;
        ecx = 0x00;
         asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
        memcpy(&l1_Cache_eax,&eax, sizeof(eax));
        memcpy(&l1_Cache_ebx,&ebx, sizeof(ebx));
        memcpy(&l1_Cache_ecx,&ecx, sizeof(ecx));
        memcpy(&l1_Cache_edx,&edx, sizeof(edx));
    
      printf("\n L1 Cache results start  \n");
      printf("\n eax = %x\n", l1_Cache_eax);
      printf("\n ebx = %x\n", l1_Cache_ebx);
      printf("\n ecx = %x\n", l1_Cache_ecx);
      printf("\n edx = %x\n", l1_Cache_edx);
      printf("\n L1 Cache results ends \n");

    //  L1 Data Cache Size and TLB End //
    
    // CPU family and model//
    
    eax = 0x01;
    ebx = 0x00;
    ecx = 0x00;
    edx = 0x00;
    
    asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
      memcpy(&cpu_family_eax,&eax, sizeof(eax));
      memcpy(&cpu_family_ebx,&ebx, sizeof(ebx));
   
printf("\n CPU Family and Model name & ID= %x\n", cpu_family_eax);
printf("\n Logical CPUs= %x\n", cpu_family_ebx);
printf("\n Therefore system has 2 logical CPUs \n");

// CPU family and model end//




   
   
    
  //cpu frequency//
  
  
      eax = 0x16;
      ebx = 0x00;
      ecx = 0x00;
      edx = 0x00;
     
     
      asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
   memcpy(&cpufreq_eax,&eax, sizeof(eax));
    memcpy(&cpufreq_ebx,&ebx, sizeof(ebx));
     memcpy(&cpufreq_ecx,&ecx, sizeof(ecx));
   
     printf("\n eax cpu frequency = %x\n", cpufreq_eax);
      printf("\n ebx = %x\n", cpufreq_ebx);
     printf("\n ecx = %x\n", cpufreq_ecx);
     
   

/* Physical and logical address width */


  eax = 0x80000008;
  ebx = 0x00;
  ecx = 0x00;
  edx = 0x00;

    
     
     
      asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
      memcpy(&physicaladdwidth_eax,&eax, sizeof(eax));
      memcpy(&physicaladdwidth_ebx,&ebx, sizeof(ebx));
      memcpy(&physicaladdwidth_ecx,&ecx, sizeof(ecx));
      memcpy(&physicaladdwidth_edx,&edx, sizeof(edx));
     
     printf("\n Physical address  \n");
      printf("\n eax = %x\n", physicaladdwidth_eax);
     printf("\n ebx = %x\n", physicaladdwidth_ebx);
      printf("\n ecx = %x\n", physicaladdwidth_ecx);
     printf("\n edx = %x\n", physicaladdwidth_edx);

// Memory hierarchy// (The value of eax remains constant and the value of ecx changes)

 eax = 0x04;
 ebx = 0x00;
  ecx = 0x03;
 edx = 0x00;



 
      asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
   memcpy(&memhie_eax,&eax, sizeof(eax));
     memcpy(&memhie_ebx,&ebx, sizeof(ebx));
   memcpy(&memhie_ecx,&ecx, sizeof(ecx));
     memcpy(&memhie_edx,&edx, sizeof(edx));
     
     printf("\n Memhie  \n");
    printf("\n eax = %x\n", memhie_eax);
     printf("\n ebx = %x\n", memhie_ebx);
    printf("\n ecx = %x\n", memhie_ecx);
     printf("\n edx = %x\n", memhie_edx);


 eax = 0x04;
  ebx = 0x00;
   ecx = 0x02;
    edx = 0x00;



 
     asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
    memcpy(&memhie_eax,&eax, sizeof(eax));
     memcpy(&memhie_ebx,&ebx, sizeof(ebx));
    memcpy(&memhie_ecx,&ecx, sizeof(ecx));
     memcpy(&memhie_edx,&edx, sizeof(edx));
     
     printf("\n Memhie  \n");
    printf("\n eax = %x\n", memhie_eax);
     printf("\n ebx = %x\n", memhie_ebx);
    printf("\n ecx = %x\n", memhie_ecx);
     printf("\n edx = %x\n", memhie_edx);

eax = 0x04;
 ebx = 0x00;
  ecx = 0x02;
  edx = 0x00;



 
     asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
    memcpy(&memhie_eax,&eax, sizeof(eax));
     memcpy(&memhie_ebx,&ebx, sizeof(ebx));
    memcpy(&memhie_ecx,&ecx, sizeof(ecx));
      memcpy(&memhie_edx,&edx, sizeof(edx));
     
      printf("\n Memhie  \n");
       printf("\n eax = %x\n", memhie_eax);
      printf("\n ebx = %x\n", memhie_ebx);
       printf("\n ecx = %x\n", memhie_ecx);
      printf("\n edx = %x\n", memhie_edx);


 eax = 0x04;
  ebx = 0x00;
   ecx = 0x01;
    edx = 0x00;



 
     asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
     memcpy(&memhie_eax,&eax, sizeof(eax));
      memcpy(&memhie_ebx,&ebx, sizeof(ebx));
     memcpy(&memhie_ecx,&ecx, sizeof(ecx));
       memcpy(&memhie_edx,&edx, sizeof(edx));
     
    printf("\n Memhie  \n");
     printf("\n eax = %x\n", memhie_eax);
    printf("\n ebx = %x\n", memhie_ebx);
     printf("\n ecx = %x\n", memhie_ecx);
    printf("\n edx = %x\n", memhie_edx);


// CPU Features // (The intel manual said that the feature flag out output will be from ecx and edx)

unsigned int feature_edx;
unsigned int feature_ecx;





 eax = 0x01;
   ebx = 0x00;
      ecx = 0x00;
       edx = 0x00;



 
     asm volatile (
                  "cpuid;"
                  : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                  :"a"(eax)
                );
   
       memcpy(&feature_edx,&edx, sizeof(edx));
     memcpy(&feature_ecx,&ecx, sizeof(ecx));
     
     
        printf("\n Feature flags  \n");
      printf("\n ebx = %x\n", memhie_edx);
       printf("\n ecx = %x\n", memhie_ecx);
 



     
     
     
  
  
  
 
  
    
  
    
}





