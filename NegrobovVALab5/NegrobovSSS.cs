using System;
using System.Collections.Generic;

namespace NegrobovVALab5
{
	[Serializable]
    public class NegrobovSSS
    {
        private List<NegrobovSSSMember> members;
    }

    public void add_member()
    {
        member = new NegrobovSSSMember;
        member.input();
        members.Add(member);
    }


    public void add_president()
    {
        president = new NegrobovSSSPresident;
        president.input();
        members.Add(president);
    }

    public void print()
    {
        if (members.Count == 0)
        {
            Console.WriteLine("There is no members in SSS");
            return;
        }

        foreach (var member in members)
        {
            member.output();
        }
    }

}
