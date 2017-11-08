using System.Collections.Generic;

namespace RulesEngine
{
    public delegate bool ConditionMethod(); //a delegate to methods containing logic to condition
    public delegate double CostMethod(); //a delegate to methods containing logic to cost

    class Rules
    {
        // Initialized the rules table in the constructor
        public Rules(ref ComputeParameters computeData)
        {
            m_cparams = computeData;
            // In here, build the rules table
            // +-------------------------------------------------------------------+
            // | Priority| Rule         |Condition              | Cost             |
            // |-------------------------------------------------------------------|
            // | 1       | Reject       | If the weight exceeds | N/A              |
            // |         |              | 50kg                  |                  |
            // |-------------------------------------------------------------------|
            // | 2       | Heavy Parcel | If the weight exceeds |$15 x Weight (kg) |
            // |         |              | 10kg                  |                  |
            // |-------------------------------------------------------------------|
            // | 3       | Small Parcel | If the volume is less |$0.05 x Volume    |
            // |         |              | than 1500             |                  | 
            // |-------------------------------------------------------------------|
            // | 4       | Medium Parcel| If the volume is less |$0.04 x Volume    |
            // |         |              | than 2500             |                  |
            // |-------------------------------------------------------------------|
            // | 5       | Large Parcel |                       |$0.03 x Volume    |
            // +-------------------------------------------------------------------+
            // use SortedDictionary to make sure that it is arranged
            // from the highest priority to the lowest priority
            m_businessrules = new SortedDictionary<int, RulesParameters>();
            RulesParameters rule1 = new RulesParameters() { Priority = 1, Rule = "Reject", Condition = conditionReject, Cost = costReject };
            RulesParameters rule2 = new RulesParameters() { Priority = 2, Rule = "Heavy Parcel", Condition = conditionHeavyParcel, Cost = costHeavyParcel };
            RulesParameters rule3 = new RulesParameters() { Priority = 3, Rule = "Small Parcel", Condition = conditionSmallParcel, Cost = costSmallParcel };
            RulesParameters rule4 = new RulesParameters() { Priority = 4, Rule = "Medium Parcel", Condition = conditionMediumParcel, Cost = costMediumParcel };
            RulesParameters rule5 = new RulesParameters() { Priority = 5, Rule = "Large Parcel", Condition = conditionLargeParcel, Cost = costLargeParcel };
            m_businessrules.Add(rule1.priority, rule1);
            m_businessrules.Add(rule2.priority, rule2);
            m_businessrules.Add(rule3.priority, rule3);
            m_businessrules.Add(rule4.priority, rule4);
            m_businessrules.Add(rule5.priority, rule5);
        }

        // Getter for the rules table.
        public SortedDictionary<int, RulesParameters> GetRules
        {
            get
            {
                return this.m_businessrules;
            }
        }

        //Below are the condition methods

        private bool conditionReject() // the condition logic for Reject
        {
            if (m_cparams.Weight > 50)
                return true;

            return false;
        }

        private bool conditionHeavyParcel() // the condition logic for Heavy Parcel
        {
            if (m_cparams.Weight > 10)
                return true;

            return false;
        }

        private bool conditionSmallParcel() // the condition logic for Small Parcel
        {
            if (m_cparams.Volume < 1500)
                return true;

            return false;
        }

        private bool conditionMediumParcel() // the condition logic for Medium Parcel
        {
            if (m_cparams.Volume < 2500)
                return true;

            return false;
        }

        private bool conditionLargeParcel() // the condition logic for Large Parcel
        {
            return true;
        }


        //Below are the cost methods

        private double costReject() // the cost logic for Reject
        {
            return 0;
        }

        private double costHeavyParcel() // the cost logic for Heavy Parcel
        {
            return (15 * m_cparams.Weight);
        }

        private double costSmallParcel() // the cost logic for Small Parcel
        {
            return (0.05 * m_cparams.Volume);
        }

        private double costMediumParcel() // the cost logic for Medium Parcel
        {
            return (0.04 * m_cparams.Volume);
        }

        private double costLargeParcel() // the cost logic for Large Parcel
        {
            return (0.03 * m_cparams.Volume);
        }

        // use SortedDictionary to make sure that it is arranged
        // from the highest priority to the lowest priority
        private SortedDictionary<int, RulesParameters> m_businessrules; // contains the rules table
        private ComputeParameters m_cparams;
    }
}
