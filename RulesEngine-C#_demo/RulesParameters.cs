/**********************************************************
* Copyright (c) 2017, Gerald Selvino
* <gerald.selvino@protonmail.com> All rights reserved.
*
* This is a parameter class for each rule that we create
* in this example. It holds the needed variables that
* our rules method needs to perform calculations
***********************************************************/

﻿namespace RulesEngine
{
    struct RulesParameters
    {
        public int Priority
        {
            get
            {
                return this.priority;
            }
            set
            {
                this.priority = value;
            }
        }
        public string Rule
        {
            get
            {
                return this.rule;
            }
            set
            {
                this.rule = value;
            }
        }
        public ConditionMethod Condition
        {
            get
            {
                return this.condition;
            }
            set
            {
                this.condition = value;
            }
        }
        public CostMethod Cost
        {
            get
            {
                return this.cost;
            }
            set
            {
                this.cost = value;
            }
        }

        private int priority;
        private string rule;
        private ConditionMethod condition;
        private CostMethod cost;
    }
}
