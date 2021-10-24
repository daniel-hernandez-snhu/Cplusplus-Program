C++ Time Clock


**Summarize the project and what problem it was solving**

   This assignment tasked us to create a clock with an updating interface. The interface would refresh every second until a user interrupted the process to add time to the clock. Two clocks were displayed, one in 24 hr time and one in 12 hr time.
   
   
    
**What did you do particularly well?**

   I felt I did a pretty good job of implementing the refresh loop and the keyboard interrupt. Finding a way to allow the program to run until any key was hit on the keyboard made it feel somewhat professional.
   
   
    
**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

   I feel like I didn't make the code very modular. Since the project didn't ask for it, I did not create any classes for the clock that could be used. I also dont like that I had to rely on windows libraries for the interrupt and screen clearing during the refresh. This meant that the program couldn't be moved to another platform without serious adjustments and rewriting sections of the code.
   
   
    
**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

   The most challenging portion of the code was tracking down a suitable way to implement the keyboard interrupt. I know that this is a common feature within operating systems, but trying to implement it at a base level was far outside my comfort with C++. In the end I relied on the windows libraries, namely kbhit from the conio.h library. I found this to be the simplest to implement. I relied on the expertise available on stackoverflow to guide me in that decision. There exist several ways to implement the keyboard interrupt, but by learning the advantages and disadvantages of each one from others on stackoverflow I managed to complete it successfully.
   
   
    
**What skills from this project will be particularly transferable to other projects or course work?**

   This project taught me a lot on how to lookup and read through the windows libraries. Windows is an immensely popular, and itself immense, operating system with dozens of years of hard work built in to make seemingly simple tasks be readily available. Programming is a lot of repurposing the work of those who came before us, and this project forced me to learn how to read the windows repository and API. I suspect this will do me well in the future.
   
   
    
**How did you make this program maintainable, readable, and adaptable?**

   While I didn't utilize separate classes within this project, I did attempt to keep it DRY. The DRY concept means that you want to not repeat yourself. At its core it means that if you are finding yourself repeating sections of code, you can probably capture that section and encapsulate it in its own function, class, or other data structure. In this way you can limit how many locations you need to visit to make an update to the code. For example, I dont need to locate several places in the code if I wanted to update the default time from 12 AM (0000 hours) to 12 pm (1200 hours). This simply needs one adjustment of one variable - the value (int time = 0;) within the main function.
