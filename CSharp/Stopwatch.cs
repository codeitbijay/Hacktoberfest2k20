using System;

class StopWatch
{
    private  int flag = 0;
    private TimeSpan start;
    private TimeSpan stop;
    
    public int Start                                                //Only set property.
    {
        set
        {
            if(flag == 0)
            {
                this.start = DateTime.Now.TimeOfDay;
                flag = 1;
            }    
            else
                throw new InvalidOperationException();
        }
    }
    
    public int Stop                                                   //Only set Property.
    {
        set
        {
            flag = 0;
             this.stop = DateTime.Now.TimeOfDay;
        }
    }
    
    public void Duration()                                                          // Calculate the Duration between two Time.
    {
        TimeSpan t = this.stop - this.start;
        Console.WriteLine($"Time Duration: " + t.ToString(@"mm\:ss\:ff"));   
    }
  }
  
class Program
{
    static void Main() 
    {
        StopWatch stopWatch = new StopWatch();
        Console.WriteLine("Hiii, Welcome To the StopWatch");
        Console.WriteLine("Start:");
        stopWatch.Start = 1;
        Console.WriteLine("Stop");
        stopWatch.Start = 1;
        stopWatch.Stop = 1;
        
        stopWatch.Duration();
    }
}
