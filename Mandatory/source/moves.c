#include "get_next_line.h"

void	turn_right(t_game *game)
{
	if (game->map[game->playerx][game->playery + 1] == 'E' && game->c == 0)
		exit(free_leaks(game));
	if (game->map[game->playerx][game->playery + 1] == 'C')
		game->c -= 1;
	if (game->map[game->playerx][game->playery + 1] == '0'
		|| game->map[game->playerx][game->playery + 1] == 'C')
	{
		game->map[game->playerx][game->playery + 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playery += 1;
		load_map(game);
 		put_player(game, game->asset, 1);
		game->moves++;
		print_moves(game);
	}
}

void	turn_left(t_game *game)
{
	if (game->map[game->playerx][game->playery - 1] == 'E' && game->c == 0)
		exit(free_leaks(game));
	if (game->map[game->playerx][game->playery - 1] == 'C')
		game->c -= 1;

	if (game->map[game->playerx][game->playery - 1] == '0'
		|| game->map[game->playerx][game->playery - 1] == 'C')
	{
		game->map[game->playerx][game->playery - 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playery -= 1;
		game->moves++;
		load_map(game);
		put_player(game, game->asset, 0);
		print_moves(game);
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->playerx + 1][game->playery] == 'E' && game->c == 0)
		exit(free_leaks(game));
	if (game->map[game->playerx + 1][game->playery] == 'C')
		game->c -= 1;
	if (game->map[game->playerx + 1][game->playery] == '0'
		|| game->map[game->playerx + 1][game->playery] == 'C')
	{
		game->map[game->playerx + 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playerx += 1;
		load_map(game);
		put_player(game, game->asset, 0);
		game->moves++;
		print_moves(game);
	}
}

void	go_up(t_game *game)
{
	if (game->map[game->playerx - 1][game->playery] == 'E' && game->c == 0)
		exit(free_leaks(game));
	if (game->map[game->playerx - 1][game->playery] == '0'
		|| game->map[game->playerx - 1][game->playery] == 'C')
	{
		if (game->map[game->playerx - 1][game->playery] == 'C')
			game->c -= 1;
		game->map[game->playerx - 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playerx -= 1;
		load_map(game);
		put_player(game, game->asset, 1);
		game->moves++;
		print_moves(game);
	}
}
