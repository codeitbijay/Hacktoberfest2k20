package com.company;
import java.lang.String;
public class ValidIPAddress
{
    public String validIPAddress(String IP) {
        if (IP.charAt(IP.length() - 1) == '.' || IP.charAt(IP.length() - 1) == ':' || IP.contains("-"))
            return "Neither";

        if (IP.contains("."))
            return checkIPV4(IP);

        if (IP.contains(":"))
            return checkIPV6(IP);


        return "Neither";
    }


    private String checkIPV4(String IP)
    {
        String [] IPV4 = IP.split("\\.");
        if(IPV4.length!=4)
            return "Neither";
        for(String i:IPV4)
        {
            if(!i.equals("0")) {
                try {
                    //if(i.length()>1){
                    if (i.charAt(0) == '0' || !isNumeric(i))
                        return "Neither";
                    //}
                } catch (Exception e) {
                    return "Neither";
                }
            }

        }
        return "IPV4";
    }

    private String checkIPV6(String IP)
    {
        String [] IPV6=IP.toLowerCase().split(":");
        if(IPV6.length!=8)
            return "Neither";
        for(String i:IPV6)
        {
            if(!i.matches("^[0-9a-f]+$")||i.length()>4)
                return "Neither";
        }
        return "IPV6";
    }
    private boolean isNumeric(String s)
    {
        boolean isN = true;
        try
        {
            int N = Integer.parseInt(s);
            if(N<0 || N>255)
                isN = false;
        }
        catch(Exception e)
        {
            isN = false;

        }
        return isN;
    }
}
