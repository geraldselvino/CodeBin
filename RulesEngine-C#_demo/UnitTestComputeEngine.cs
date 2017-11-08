using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using RulesEngine;
// As is common with basic unit tests, we will only test the public methods/interfaces
// of a class. The ComputeEngine class contains only 1 public method named calculateCost.
namespace RulesEngine_UnitTest
{
    [TestClass]
    public class UnitTestComputeEngine
    {
        private ComputeEngine cengine;
        private KeyValuePair<double, string> output;

        [TestInitialize]
        public void initTest()
        {
            // Initialize the ComputeEngine class
            cengine = new ComputeEngine();
        }

        [TestMethod]
        public void calculateCost_MediumParcel()
        {
            // These are the inputs
            double weight = 10;
            double height = 20;
            double width = 5;
            double depth = 20;

            // These are the expected results
            double expectedcost = 80;
            string expectedcategory = "Medium Parcel";

            // Execute the calculateCost method
            output = cengine.calculateCost(weight, height, width, depth);

            // Compare the output from the expected results above
            Assert.AreEqual(expectedcost, output.Key);
            Assert.AreEqual(expectedcategory, output.Value);
        }

        [TestMethod]
        public void calculateCost_HeavyParcel()
        {
            // These are the inputs
            double weight = 22;
            double height = 5;
            double width = 5;
            double depth = 5;

            // These are the expected results
            double expectedcost = 330;
            string expectedcategory = "Heavy Parcel";

            // Execute the calculateCost method
            output = cengine.calculateCost(weight, height, width, depth);

            // Compare the output from the expected results above
            Assert.AreEqual(expectedcost, output.Key, 0);
            Assert.AreEqual(expectedcategory, output.Value);
        }

        [TestMethod]
        public void calculateCost_SmallParcel()
        {
            // These are the inputs
            double weight = 2;
            double height = 3;
            double width = 10;
            double depth = 12;

            // These are the expected results
            double expectedcost = 18;
            string expectedcategory = "Small Parcel";

            // Execute the calculateCost method
            output = cengine.calculateCost(weight, height, width, depth);

            // Compare the output from the expected results above
            Assert.AreEqual(expectedcost, output.Key, 0);
            Assert.AreEqual(expectedcategory, output.Value);
        }

        [TestMethod]
        public void calculateCost_Reject()
        {
            // These are the inputs
            double weight = 110;
            double height = 20;
            double width = 55;
            double depth = 120;

            // These are the expected results
            double expectedcost = 0; // In the ComputeEngine class, N/A is zero. A mapping was done
                                     // in the application to map zero to the string 'N/A'
            string expectedcategory = "Reject";

            // Execute the calculateCost method
            output = cengine.calculateCost(weight, height, width, depth);

            // Compare the output from the expected results above
            Assert.AreEqual(expectedcost, output.Key);
            Assert.AreEqual(expectedcategory, output.Value);
        }
    }
}
