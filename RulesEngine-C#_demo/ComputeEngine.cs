using System.Collections.Generic;

namespace RulesEngine
{
    public class ComputeEngine
    {
        //constructors
        public ComputeEngine() { }
        public ComputeEngine(double weight, double height, double width, double depth)
        {
            m_cparams.Weight = weight;
            m_cparams.Height = height;
            m_cparams.Width = width;
            m_cparams.Depth = depth;

        }
        public KeyValuePair<double, string> calculateCost()
        {
            // Loop the rules table from the highest priority to the lowest since we use SortedDictionary
            // evaluating the condition if it's true, the first one that returns
            // true is the rule with the highest priority that fulfills the condition
            // since the rules are arranged from highest to lowest priority
            Rules businessrules = new Rules(ref m_cparams);
            foreach (KeyValuePair<int, RulesParameters> ruleitem in businessrules.GetRules)
            {
                if (ruleitem.Value.condition())
                {
                    return new KeyValuePair<double, string>(ruleitem.Value.cost(), ruleitem.Value.rule);
                }
            }

            return new KeyValuePair<double, string>(); // No rules fulfilled the condition, return blank
        }
        public KeyValuePair<double, string> calculateCost(double weight, double height, double width, double depth)
        {
            m_cparams.Weight = weight;
            m_cparams.Height = height;
            m_cparams.Width = width;
            m_cparams.Depth = depth;

            return calculateCost();
        }

        private ComputeParameters m_cparams;
    }

}
