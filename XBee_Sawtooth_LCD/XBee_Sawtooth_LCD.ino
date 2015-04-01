
/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft;

int incomingByte = 0;      // a variable to read incoming serial data into
int counter = 0;
float x1, y1, x2, y2;
const float spacing = 1.5;

void setup() {
  Serial.begin(9600);
  tft.reset();
  tft.begin();
  tft.setRotation(1); // origin l.upper landscape
  tft.fillScreen(BLUE);
}

void loop() {
 if (Serial.available() > 0) {
   incomingByte = Serial.read();
   
   if (counter > tft.width()/spacing) {
    counter = 0;
    tft.fillScreen(BLUE);
   }
   
   if (counter == 0) {
       x1 = 0;
       y1 = tft.height() - incomingByte;
   }
   
   if (counter > 0) {
     x2 = counter*spacing;
     // Change origin to left, bottom
     y2 = tft.height() - incomingByte;
     tft.drawLine(x1, y1, x2, y2, WHITE);
     x1 = x2;
     y1 = y2;    
    }
    
   counter++;
  }
}
