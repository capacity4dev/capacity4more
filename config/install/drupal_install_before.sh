# Clear memcache if configured
if [ "$MEMCACHE_HOST" != "" ] && [ "$MEMCACHE_PORT" != "" ]; then
    nc $MEMCACHE_HOST $MEMCACHE_PORT <<<"flush_all"
fi