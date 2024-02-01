<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'database' );
/** MySQL database username */
define( 'DB_USER', 'user' );
/** MySQL database password */
define( 'DB_PASSWORD', 'user_pwd' );
/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

define( 'DB_CHARSET', 'utf8' );

define('WPMS_ON', false ); # Turn of email feature, otherwise error during build

$table_prefix = 'wp_';

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
?>