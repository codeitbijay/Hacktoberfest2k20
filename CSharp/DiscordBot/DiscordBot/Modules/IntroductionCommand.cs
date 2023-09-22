using Discord.Commands;
using System;
using System.Linq;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Net.Http;
using DiscordBot.Services;
namespace DiscordBot.Modules
{
    public class IntroductionCommand : ModuleBase
    {
        
        [Command("Hello")]
        public async Task SayHello(params String[] stringArray)
        {        
            var user = Context.User;
            await ReplyAsync($"Hello, {user.Mention}");
            return;                       
        }
    }
}