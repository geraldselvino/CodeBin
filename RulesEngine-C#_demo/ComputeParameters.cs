/**********************************************************
* Copyright (c) 2017, Gerald Selvino
* <gerald.selvino@protonmail.com> All rights reserved.
*
* The parameter class used to hold the parameters passed
* from the calling client to the Rules class
***********************************************************/

﻿namespace RulesEngine
{
    struct ComputeParameters
    {
        public double Weight
        {
            get
            {
                return this.weight;
            }
            set
            {
                this.weight = value;
            }
        }
        public double Height
        {
            get
            {
                return this.height;
            }
            set
            {
                this.height = value;
            }
        }
        public double Width
        {
            get
            {
                return this.width;
            }
            set
            {
                this.width = value;
            }
        }
        public double Depth
        {
            get
            {
                return this.depth;
            }
            set
            {
                this.depth = value;
            }
        }
        public double Volume
        {
            get
            {
                return (this.height * this.width * this.depth);
            }
        }
        private double weight; //kg
        private double height; //cm
        private double width; //cm
        private double depth; //cm
    }
}
