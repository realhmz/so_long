#include "get_next_line.h"

void	turn_right(t_game *game)
{
	if (game->map[game->playerx][game->playery + 1] == 'E' && game->c == 0)
	{
		printf("Congrats you win!!\n");
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (game->map[game->playerx][game->playery + 1] == 'C')
	{
		play_kill(game->sound);
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx][game->playery + 1] == '0'
		|| game->map[game->playerx][game->playery + 1] == 'C')
	{
		game->map[game->playerx][game->playery + 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		render_sky(game, game->asset);
		// play_walk(game->sound);
		game->playery += 1;
		load_map(game);
		put_player(game, game->asset, 1);
		put_enemy(game, game->asset, -1);
		game->moves++;
		print_moves(game);
	}
}

void	turn_left(t_game *game)
{
	if (game->map[game->playerx][game->playery - 1] == 'E' && game->c == 0)
	{
		printf("You win Congrats!!\n\n");
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (game->map[game->playerx][game->playery - 1] == 'C')
	{
		play_kill(game->sound);
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx][game->playery - 1] == '0'
		|| game->map[game->playerx][game->playery - 1] == 'C')
	{
		game->map[game->playerx][game->playery - 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playery -= 1;
		game->moves++;
		render_sky(game, game->asset);
		load_map(game);
		put_player(game, game->asset, 0);
		put_enemy(game, game->asset, -1);
		print_moves(game);
	}
}
void	go_up(t_game *game)
{
	if (game->map[game->playerx + 1][game->playery] == 'E' && game->c == 0)
	{
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (game->map[game->playerx + 1][game->playery] == 'C')
	{
		play_kill(game->sound);
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx + 1][game->playery] == '0' || game->map[game->playerx
		+ 1][game->playery] == 'C')
	{
		game->map[game->playerx + 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		render_sky(game, game->asset);
		play_walk(game->sound);
		game->playerx += 1;
		load_map(game);
		put_player(game, game->asset, 1);
		put_enemy(game, game->asset, -1);
		print_moves(game);
		game->moves++;
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->playerx - 1][game->playery] == 'E' && game->c == 0)
	{
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (game->map[game->playerx - 1][game->playery] == 'C')
	{
		play_kill(game->sound);
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx - 1][game->playery] == '0' || game->map[game->playerx
		- 1][game->playery] == 'C')
	{
		render_sky(game, game->asset);
		play_walk(game->sound);
		game->map[game->playerx - 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playerx -= 1;
		load_map(game);
		put_player(game, game->asset, 1);
		put_enemy(game, game->asset, -1);
		print_moves(game);
		game->moves++;
	}
}
