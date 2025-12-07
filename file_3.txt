#การเปิดไฟล์ fopen()
FILE *fp = fopen("filename","mode")

#mode ทั้งหมด
"r"  ใช้อ่านไฟล์ หากไฟล์ไม่มีจะ error	  
"w"  ใช้เขียนไฟล์ โดยเขียนทับค่าเดิม หากไม่มีไฟล์นั้นจะสร้างไฟล์ใหม่ขึ้นมา	 
"a"  ใช้เขียนไฟล์ โดยเขียนต่อท้ายค่าเดิม หากไม่มีไฟล์นั้นจะสร้างไฟล์ใหม่ขึ้นมา	 
"r+" ใช้อ่านและแก้ไขไฟล์ หากไฟล์ไม่มีจะ error	 
"w+" ใช้อ่านและเขียนไฟล์ โดยเขียนทับค่าเดิม หากไม่มีไฟล์นั้นจะสร้างไฟล์ใหม่ขึ้นมา	     
"a+" ใช้อ่านและเขียนไฟล์ โดยเขียนต่อท้ายค่าเดิม หากไม่มีไฟล์นั้นจะสร้างไฟล์ใหม่ขึ้นมา	  

#การปิดไฟล์ fclose()
fclose(fp);

#อ่าน–เขียนไฟล์แบบตัวอักษร

fputc() เขียน 1 ตัวอักษร ลงไฟล์
fputc('A', fp);

fgetc() อ่าน 1 ตัวอักษร จากไฟล์
char c = fgetc(fp);
printf("%c", c);

#อ่าน–เขียนแบบบรรทัด

fprintf() เขียนข้อมูลลงไฟล์แบบ format
fprintf(fp, "My score = %d", score);

fscanf() อ่านข้อมูลแบบ format จากไฟล์
fscanf(fp, "%d", &n);

fgets() อ่าน 1 บรรทัด จากไฟล์ (รวม space ด้วย)
char line[100];
fgets(line, 100, fp);

fputs() เขียน string ลงไฟล์
fputs("Hello\n", fp);

#อ่านและเขียน struct
fwrite() → เขียนเป็น block
fread() → อ่านเป็น block

#ตัวอย่างเขียน struct ลงไฟล์

struct Student {
    char name[20];
    int age;
};

struct Student s = {"John", 20};

FILE *fp = fopen("data.bin", "wb");
fwrite(&s, sizeof(struct Student), 1, fp);
fclose(fp);

#ตัวอย่างอ่าน struct

FILE *fp = fopen("data.bin", "rb");
struct Student s;

fread(&s, sizeof(struct Student), 1, fp);
printf("%s %d", s.name, s.age);
fclose(fp);


