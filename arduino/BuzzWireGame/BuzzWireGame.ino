
// struct seven_seg {
//     int address;
//     int value;
// };

// void seven_seg_write(struct* seven_seg);

#define LE      2
#define A       3
#define B       4
#define C       5
#define D       6
void setup() {
    pinMode(LE, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    
    digitalWrite(LE, LOW);

    Serial.begin(9600);
}

int seven_seg_val{0};
bool a, b, c, d;

void loop() {
    a = seven_seg_val & 0x1;
    b = seven_seg_val & 0x2;
    c = seven_seg_val & 0x4;
    d = seven_seg_val & 0x8;
    digitalWrite(A, a);
    digitalWrite(B, b);
    digitalWrite(C, c);
    digitalWrite(D, d);
    digitalWrite(LE, HIGH);
    digitalWrite(LE, LOW);

    seven_seg_val = seven_seg_val == 9 ? 0 : seven_seg_val+1;

    Serial.print(seven_seg_val);
    Serial.print(": ");
    Serial.print(d);
    Serial.print(c);
    Serial.print(b);
    Serial.println(a);
    delay(500);
}