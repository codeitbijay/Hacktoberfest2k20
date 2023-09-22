using System;
using Discord;
using Discord.Net;
using Discord.Commands;
using Discord.WebSocket;
using System.Threading.Tasks;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Configuration.Json;
using System.Collections.Generic;
using Microsoft.Extensions.DependencyInjection;
using System.Linq;
using System.Net.Http;
using DiscordBot.Services;
namespace DiscordBot
{
   internal class Program
    {     
        private DiscordSocketClient _client;
        private readonly IConfiguration _config;
        static void Main(string[] args)
        {
            new Program().MainAsync().GetAwaiter().GetResult();
        }

        public Program()
        {
            var _builder = new ConfigurationBuilder().SetBasePath(AppContext.BaseDirectory).AddJsonFile(path: "appSettings.json");
            _config = _builder.Build();

        }

        public async Task MainAsync()
        {
            using (var services = ConfigureServices())
            {                
                var client = services.GetRequiredService<DiscordSocketClient>();
                _client = client;

                client.Log += LogAsync;
                client.Ready += ReadyAsync;
                services.GetRequiredService<CommandService>().Log += LogAsync;                

                await client.LoginAsync(TokenType.Bot, _config["Token"]);
                await client.StartAsync();

                await services.GetRequiredService<CommandHandler>().InitializeAsync();

                await Task.Delay(-1);
            }          
        }

        private Task LogAsync(LogMessage log)
        {
            Console.WriteLine(log.ToString());
            return Task.CompletedTask;
        }

        private Task ReadyAsync()
        {
            Console.WriteLine($"Connected as -> [{_client.CurrentUser}] :)");
            return Task.CompletedTask;
        }
        private ServiceProvider ConfigureServices()
        {
            return new ServiceCollection()
                .AddSingleton(_config)
                .AddSingleton<DiscordSocketClient>()
                .AddSingleton<CommandService>()
                .AddSingleton<CommandHandler>()                
                .BuildServiceProvider();
        }   
    }
}
