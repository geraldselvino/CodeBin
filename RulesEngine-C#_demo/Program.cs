using System;
using System.Collections.Generic;

namespace RulesEngine
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("+----------------------------+");
            Console.WriteLine("| Scalable Rules Engine demo |");
            Console.WriteLine("| Cost of delivery calculator|");
            Console.Write    ("+----------------------------+");
            bool endloop = false;
            do
            {
                Console.WriteLine("\n[c]alculate cost");
                Console.WriteLine("[q]uit\n");
                Console.Write("Enter your selection: ");
                int choice = Console.Read();
                FlushStdin();
                switch (choice)
                {
                    case 'c':
                    case 'C':
                        Console.Write("\nWeight: ");
                        double weight;
                        if (!double.TryParse(Console.ReadLine(), out weight)
                            || weight <= 0)
                        {
                            Console.WriteLine("\nInvalid input for Weight");
                            break;
                        }
                        Console.Write("Height: ");
                        double height;
                        if (!double.TryParse(Console.ReadLine(), out height)
                            || height <= 0)
                        {
                            Console.WriteLine("\nInvalid input for Height");
                            break;
                        }
                        Console.Write("Width: ");
                        double width;
                        if (!double.TryParse(Console.ReadLine(), out width)
                            || width <= 0)
                        {
                            Console.WriteLine("\nInvalid input for Width");
                            break;
                        }
                        Console.Write("Depth: ");
                        double depth;
                        if (!double.TryParse(Console.ReadLine(), out depth)
                            || depth <= 0)
                        {
                            Console.WriteLine("\nInvalid input for Depth");
                            break;
                        }
                        // Call compute engine class
                        ComputeEngine cengine = new ComputeEngine(weight, height, width, depth);
                        KeyValuePair<double, string> output = cengine.calculateCost();
                        Console.WriteLine("\nCategory: " + output.Value);
                        if (output.Key > 0)
                            Console.WriteLine("Cost: $" + output.Key);
                        else
                            Console.WriteLine("Cost: N/A");

                        break;
                    case 'Q':
                    case 'q':
                        Console.WriteLine("Graceful exit");
                        endloop = true;
                        break;
                    default:
                        Console.WriteLine("Invalid choice");
                        break;
                }
            } while (!endloop);
        }

        private static void FlushStdin()
        {
            while (Console.In.Peek() != -1)
                Console.In.Read();
        }
    }
}
