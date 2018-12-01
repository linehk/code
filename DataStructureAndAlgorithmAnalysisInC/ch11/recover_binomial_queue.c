//  恢复二项队列的过程

for (R = 0; R <= floor(logN); R++)
        while (|Lr| >= 2)
        {
                Remove two trees from Lr;
                Merge the two trees into a new tree;
                Add the new tree to Lr+1;
        }