/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
  Sends byte value per XBee v1.
*/

unsigned long LoopTimer = 0;
byte outputValue = 0;

const int LoopTime50 = 50;
const int LoopTime100 = 100;

void setup() {
 Serial.begin(9600);
}

void loop() {
   if (millis() >= LoopTimer + LoopTime50)
  {
    LoopTimer += LoopTime50;
    outputValue += 8;
    Serial.write(outputValue);
  }
}
